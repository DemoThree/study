#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_TREE_NODES 511
#define MAX_CODE_LEN 256
#define BUFFER_SIZE 4096

// 哈夫曼树节点结构
typedef struct HuffmanNode
{
    unsigned char data;        // 字符
    int freq;                  // 频率
    int is_leaf;               // 是否是叶节点
    struct HuffmanNode *left;  // 左子节点
    struct HuffmanNode *right; // 右子节点
} HuffmanNode;

// 哈夫曼编码表
typedef struct
{
    unsigned char code[MAX_CODE_LEN]; // 编码
    int length;                       // 编码长度
} HuffmanCode;

// 最小堆结构
typedef struct
{
    HuffmanNode **nodes; // 节点指针数组
    int size;            // 当前堆大小
    int capacity;        // 堆容量
} MinHeap;

// 压缩文件头信息
typedef struct
{
    unsigned char magic[4];   // 魔数"HFMN"
    uint32_t original_size;   // 原始文件大小
    uint32_t freq_table[256]; // 频率表
    uint8_t padding_bits;     // 填充位数
} FileHeader;

// 创建哈夫曼节点
HuffmanNode *create_node(unsigned char data, int freq, int is_leaf)
{
    HuffmanNode *node = (HuffmanNode *)malloc(sizeof(HuffmanNode));
    if (!node)
    {
        perror("内存分配失败");
        exit(1);
    }
    node->data = data;
    node->freq = freq;
    node->is_leaf = is_leaf;
    node->left = node->right = NULL;
    return node;
}

// 创建最小堆
MinHeap *create_minheap(int capacity)
{
    MinHeap *heap = (MinHeap *)malloc(sizeof(MinHeap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->nodes = (HuffmanNode **)malloc(capacity * sizeof(HuffmanNode *));
    return heap;
}

// 交换堆中两个节点
void swap_nodes(HuffmanNode **a, HuffmanNode **b)
{
    HuffmanNode *temp = *a;
    *a = *b;
    *b = temp;
}

// 最小堆化
void minheapify(MinHeap *heap, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size && heap->nodes[left]->freq < heap->nodes[smallest]->freq)
        smallest = left;
    if (right < heap->size && heap->nodes[right]->freq < heap->nodes[smallest]->freq)
        smallest = right;

    if (smallest != idx)
    {
        swap_nodes(&heap->nodes[smallest], &heap->nodes[idx]);
        minheapify(heap, smallest);
    }
}

// 插入堆
void insert_heap(MinHeap *heap, HuffmanNode *node)
{
    if (heap->size == heap->capacity)
    {
        printf("堆已满\n");
        return;
    }

    heap->size++;
    int i = heap->size - 1;
    heap->nodes[i] = node;

    while (i != 0 && heap->nodes[(i - 1) / 2]->freq > heap->nodes[i]->freq)
    {
        swap_nodes(&heap->nodes[i], &heap->nodes[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// 提取最小节点
HuffmanNode *extract_min(MinHeap *heap)
{
    if (heap->size <= 0)
        return NULL;
    if (heap->size == 1)
    {
        heap->size--;
        return heap->nodes[0];
    }

    HuffmanNode *root = heap->nodes[0];
    heap->nodes[0] = heap->nodes[heap->size - 1];
    heap->size--;
    minheapify(heap, 0);

    return root;
}

// 构建哈夫曼树
HuffmanNode *build_huffman_tree(uint32_t freq[])
{
    MinHeap *heap = create_minheap(256);

    // 为每个出现过的字符创建节点并插入堆中
    for (int i = 0; i < 256; i++)
    {
        if (freq[i] > 0)
        {
            HuffmanNode *node = create_node(i, freq[i], 1);
            insert_heap(heap, node);
        }
    }

    // 构建哈夫曼树
    while (heap->size > 1)
    {
        HuffmanNode *left = extract_min(heap);
        HuffmanNode *right = extract_min(heap);

        HuffmanNode *parent = create_node(0, left->freq + right->freq, 0);
        parent->left = left;
        parent->right = right;

        insert_heap(heap, parent);
    }

    HuffmanNode *root = extract_min(heap);
    free(heap->nodes);
    free(heap);

    return root;
}

// 生成哈夫曼编码表
void generate_codes(HuffmanNode *root, HuffmanCode codes[], unsigned char code[], int depth)
{
    if (root->is_leaf)
    {
        for (int i = 0; i < depth; i++)
        {
            codes[root->data].code[i] = code[i];
        }
        codes[root->data].length = depth;
        return;
    }

    if (root->left)
    {
        code[depth] = 0;
        generate_codes(root->left, codes, code, depth + 1);
    }

    if (root->right)
    {
        code[depth] = 1;
        generate_codes(root->right, codes, code, depth + 1);
    }
}

// 压缩文件
void compress_file(const char *input_file, const char *output_file)
{
    FILE *in = fopen(input_file, "rb");
    FILE *out = fopen(output_file, "wb");

    if (!in || !out)
    {
        perror("文件打开失败");
        exit(1);
    }

    uint32_t freq[256] = {0};
    unsigned char buffer[BUFFER_SIZE];
    size_t bytes_read;

    // 统计字符频率
    fseek(in, 0, SEEK_END);
    uint32_t file_size = ftell(in);
    fseek(in, 0, SEEK_SET);

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, in)) > 0)
    {
        for (size_t i = 0; i < bytes_read; i++)
        {
            freq[buffer[i]]++;
        }
    }

    // 构建哈夫曼树
    HuffmanNode *root = build_huffman_tree(freq);

    // 生成编码表
    HuffmanCode codes[256] = {0};
    unsigned char temp_code[MAX_CODE_LEN];
    generate_codes(root, codes, temp_code, 0);

    // 写入文件头
    FileHeader header;
    memcpy(header.magic, "HFMN", 4);
    header.original_size = file_size;
    header.padding_bits = 0;
    memcpy(header.freq_table, freq, sizeof(freq));

    fwrite(&header, sizeof(FileHeader), 1, out);

    // 重新读取文件并压缩数据
    fseek(in, 0, SEEK_SET);

    unsigned char write_buffer = 0;
    int bit_count = 0;

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, in)) > 0)
    {
        for (size_t i = 0; i < bytes_read; i++)
        {
            unsigned char ch = buffer[i];
            HuffmanCode code = codes[ch];

            for (int j = 0; j < code.length; j++)
            {
                write_buffer <<= 1;
                write_buffer |= code.code[j];
                bit_count++;

                if (bit_count == 8)
                {
                    fwrite(&write_buffer, 1, 1, out);
                    write_buffer = 0;
                    bit_count = 0;
                }
            }
        }
    }

    // 处理最后的不足8位的位
    if (bit_count > 0)
    {
        write_buffer <<= (8 - bit_count);
        fwrite(&write_buffer, 1, 1, out);
        header.padding_bits = 8 - bit_count;

        // 更新文件头中的填充位数
        fseek(out, offsetof(FileHeader, padding_bits), SEEK_SET);
        fwrite(&header.padding_bits, 1, 1, out);
    }

    // 释放内存
    // 注意：这里需要递归释放哈夫曼树，为了简洁省略
    // 在实际应用中应添加释放函数

    fclose(in);
    fclose(out);

    printf("压缩完成！\n");
    printf("原始大小: %u 字节\n", header.original_size);
    printf("压缩后大小: %ld 字节\n", ftell(out));
    printf("压缩率: %.2f%%\n", (double)ftell(out) / header.original_size * 100);
}

// 解压文件
void decompress_file(const char *input_file, const char *output_file)
{
    FILE *in = fopen(input_file, "rb");
    FILE *out = fopen(output_file, "wb");

    if (!in || !out)
    {
        perror("文件打开失败");
        exit(1);
    }

    // 读取文件头
    FileHeader header;
    fread(&header, sizeof(FileHeader), 1, in);

    // 验证魔数
    if (memcmp(header.magic, "HFMN", 4) != 0)
    {
        printf("错误：不是有效的哈夫曼压缩文件\n");
        fclose(in);
        fclose(out);
        return;
    }

    // 重建哈夫曼树
    HuffmanNode *root = build_huffman_tree(header.freq_table);

    // 解码数据
    HuffmanNode *current = root;
    unsigned char buffer[BUFFER_SIZE];
    size_t bytes_read;
    uint32_t bytes_written = 0;
    int bit_count = 0;
    unsigned char byte;

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, in)) > 0 &&
           bytes_written < header.original_size)
    {
        for (size_t i = 0; i < bytes_read && bytes_written < header.original_size; i++)
        {
            byte = buffer[i];

            for (int j = 7; j >= 0 && bytes_written < header.original_size; j--)
            {
                int bit = (byte >> j) & 1;

                if (bit == 0)
                    current = current->left;
                else
                    current = current->right;

                if (current->is_leaf)
                {
                    fwrite(&current->data, 1, 1, out);
                    bytes_written++;
                    current = root;
                }
            }
        }
    }

    fclose(in);
    fclose(out);

    printf("解压完成！\n");
    printf("原始大小: %u 字节\n", header.original_size);
    printf("输出大小: %u 字节\n", bytes_written);
}

// 释放哈夫曼树内存
void free_huffman_tree(HuffmanNode *root)
{
    if (root == NULL)
        return;

    if (!root->is_leaf)
    {
        free_huffman_tree(root->left);
        free_huffman_tree(root->right);
    }

    free(root);
}

// 显示帮助信息
void show_help()
{
    printf("哈夫曼文件压缩/解压程序\n");
    printf("使用方法:\n");
    printf("  compress <输入文件> <输出文件>  - 压缩文件\n");
    printf("  decompress <输入文件> <输出文件> - 解压文件\n");
    printf("  help                           - 显示此帮助\n");
    printf("示例:\n");
    printf("  compress input.txt output.hfm\n");
    printf("  decompress output.hfm output.txt\n");
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        show_help();
        return 1;
    }

    if (strcmp(argv[1], "compress") == 0 && argc == 4)
    {
        compress_file(argv[2], argv[3]);
    }
    else if (strcmp(argv[1], "decompress") == 0 && argc == 4)
    {
        decompress_file(argv[2], argv[3]);
    }
    else if (strcmp(argv[1], "help") == 0)
    {
        show_help();
    }
    else
    {
        printf("错误：无效的参数\n");
        show_help();
        return 1;
    }

    return 0;
}
// SAT 碰撞检测 分离轴算法
bool satCollision(const std::vector<Vec2> &vertsA, const std::vector<Vec2> &vertsB)
{
    auto axes = getEdgeNormals(vertsA);
    auto axesB = getEdgeNormals(vertsB);
    axes.insert(axes.end(), axesB.begin(), axesB.end()); // 合并所有轴

    for (const auto &axis : axes)
    {
        float minA, maxA, minB, maxB;
        projectPolygon(vertsA, axis, minA, maxA);
        projectPolygon(vertsB, axis, minB, maxB);
        if (maxA < minB || maxB < minA)
            return false; // 有间隙，不相交
    }
    return true; // 所有轴都重叠
}
// 将多边形投影到指定轴上，返回投影区间
Projection project(const Polygon &poly, const Vec2 &axis)
{
    float min = std::numeric_limits<float>::max();
    float max = -std::numeric_limits<float>::max();
    for (const auto &v : poly.vertices)
    {
        float proj = v.dot(axis);
        if (proj < min)
            min = proj;
        if (proj > max)
            max = proj;
    }
    return {min, max};
}