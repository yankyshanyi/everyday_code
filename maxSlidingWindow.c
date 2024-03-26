
#include <stdlib.h>
#include <stdio.h>

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    int n = numsSize;
    int queue[n]; //队列
    int front = 0, rear = -1; //队首 队尾
    int left = 0, right = 0; //窗口左下标 窗口右下标
    while (right < n) { //窗口右移至终点
        while (rear >= front && nums[right] > queue[rear]) 
            rear--; //维护队列的单调性（非递增），即保证队首元素就是当前窗口的最大值
        queue[++rear] = nums[right++]; //入队下一个窗口可能的最大值
        if (left + k <= right) { //窗口大小大于k
            if (nums[left] == queue[front]) 
                front++; //如果最大值已经在窗口的左边，则将它永久出队
            else 
                nums[left] = queue[front]; //否则记录最大值进原数组中
            left++; //左框右移
        }
    }
    *returnSize = n - k + 1;
    return nums; //返回原数组
}

int main(void) 
{
    int k = 3;

    int nums[8] = {1,3,-1,-3,5,3,6,7};
    int nums_debug[8] = {};
    int length = sizeof(nums)/sizeof(nums[0]);
    printf("length = %d\n",length);

    int *ptr = (int *)nums;

    int returnSize_ptr;
    maxSlidingWindow(ptr,  8,  k, &returnSize_ptr);
    printf("returnSize_ptr = %d\n",returnSize_ptr);

    int n = 0;
    for(; n < returnSize_ptr;n++)
        printf("nums_return = %d\n",nums[n]);
	return 0;
}