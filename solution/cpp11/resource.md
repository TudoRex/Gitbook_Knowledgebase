# c++ 11 vc 资源引入

## 二进制资源链接到dll或exe
类似之前在linux下手动调用linker编译二进制文件
```
HINSTANCE HInst = GetModuleHandle(TEXT("xxx.dll")); // 嵌入资源的dll或exe
HRSRC hRes = FindResource(hInst, MAKEINTRESOURCE(IDR_CSV1), TEXT("csv")); //导入时资源类别csv
HGLOBAL hResData = LoadResource(hInst, hRes);
void* bufer = LockResource(hResData);
auto size = SizeofResource(hInst, hRes);
```