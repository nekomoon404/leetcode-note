#include <cstddef>

void* my_memcpy(void* dest, const void* src, size_t count) {
  if (dest == nullptr || src == nullptr) {
    return dest;
  }
  // 转换为字节
  char* dest_ptr = static_cast<char*>(dest);
  const char* src_ptr = static_cast<const char*>(src);

  // 处理内存重叠的情况
  if (dest_ptr > src_ptr && dest_ptr < src_ptr + count) {
    // 从后向前拷贝
    for (size_t i = count; i > 0; --i) {
      dest_ptr[i - 1] = src_ptr[i - 1];
    }
  } else {
    // 普通情况，从前向后拷贝
    for (size_t i = 0; i < count; ++i) {
      dest_ptr[i] = src_ptr[i];
    }
  }
  return dest;
}

// 测试用例
#include <cassert>
#include <cstring>
#include <iostream>
using namespace std;
int main() {
  {
    char src[] = "Hello, World";
    char dest[20] = {0};
    my_memcpy(dest, src, strlen(src) + 1);
    assert(strcmp(dest, src) == 0);
  }
  {
    // 内存重叠：目标在源之后
    char src[] = "0123456789";
    my_memcpy(src + 5, src, 5);
    assert(strcmp(src + 5, "01234") == 0);
  }
  {
    // 内存重叠：目标在源之前
    char src[] = "0123456789";
    my_memcpy(src, src + 5, 5);
    assert(strcmp(src, "5678956789") == 0);
  }
  {
    // 空指针
    char src[10] = {0};
    assert(my_memcpy(nullptr, src, 10) == nullptr);
    assert(my_memcpy(src, nullptr, 10) == src);
  }

  cout << "All tests passed" << endl;
  return 0;
}