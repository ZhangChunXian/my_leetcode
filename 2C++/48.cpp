#include "cpp_header.h"
/**
 * @file 48.cpp
 * @author ZhangChunXian (1836891291@qq.com)
 * @version 0.1
 * @date 2021-01-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */
// 如果不申请额外N²个空间的话, 就不会写了
/**
 * @brief 评论区最高赞: 最直白蛮力的方法, 先转置后镜像对称
 * 
 */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 将matrix数组转置
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < i; j++) {
                int tem = matrix[j][i];
                matrix[j][i] = matrix[i][j];
                matrix[i][j] = tem;
            }
        }

        // 镜像对称
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.size()/2; j++) {
                int tem = matrix[i][matrix.size() - 1 - j];
                matrix[i][matrix.size() - 1- j] = matrix[i][j];
                matrix[i][j] = tem;
                // 上面三句可以用swap(matrix[i][matrix.size() - 1 - j], matrix[i][j])代替
            }
        }
    }
};