#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// 定义标准Base64字符表
const char STANDARD_BASE64_TABLE[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

// 示例：自定义Base64字符表
const char CUSTOM_BASE64_TABLE[] = "ZYXWVUTSRQPONMLKJIHGFEDCBAabcdefghijklmnopqrstuvwxyz0123456789-*";

// 获取字符在Base64表中的索引
int get_index(const char *table, char c) {
    for (int i = 0; i < 64; i++) {
        if (table[i] == c) {
            return i;
        }
    }
    return -1; // 不在表中
}

// 解码Base64数据
int decode_base64(const char *input, char *output, const char *custom_table) {
    int len = strlen(input);
    int padding = 0;

    // 统计填充符号'='的数量
    if (len > 0 && input[len - 1] == '=') padding++;
    if (len > 1 && input[len - 2] == '=') padding++;

    // 解码缓冲区
    int output_len = 0;
    uint32_t buffer = 0; // 24位缓冲区

    for (int i = 0; i < len; i++) {
        if (input[i] == '=') break; // 跳过填充符号

        int index = get_index(custom_table, input[i]);
        if (index == -1) {
            fprintf(stderr, "Invalid character in input: %c\n", input[i]);
            return -1; // 非法字符
        }

        buffer = (buffer << 6) | index; // 每次加入6位
        if ((i + 1) % 4 == 0) {
            // 每4个字符生成3个字节
            output[output_len++] = (buffer >> 16) & 0xFF;
            output[output_len++] = (buffer >> 8) & 0xFF;
            output[output_len++] = buffer & 0xFF;
            buffer = 0;
        }
    }

    // 处理剩余数据
    if (padding > 0) {
        buffer = buffer << (6 * padding); // 填充剩余位
        if (padding == 1) {
            output[output_len++] = (buffer >> 16) & 0xFF;
            output[output_len++] = (buffer >> 8) & 0xFF;
        } else if (padding == 2) {
            output[output_len++] = (buffer >> 16) & 0xFF;
        }
    }

    return output_len; // 返回解码后的长度
}

int main() {
    // 示例输入：自定义Base64编码的字符串
    const char *encoded_data = "ZY-*ZY-";

    // 输出缓冲区
    char decoded_data[256] = {0};

    // 调用解码函数
    int decoded_len = decode_base64(encoded_data, decoded_data, CUSTOM_BASE64_TABLE);

    if (decoded_len >= 0) {
        printf("Decoded data (length %d): ", decoded_len);
        for (int i = 0; i < decoded_len; i++) {
            printf("%c", decoded_data[i]);
        }
        printf("\n");
    }

    return 0;
}