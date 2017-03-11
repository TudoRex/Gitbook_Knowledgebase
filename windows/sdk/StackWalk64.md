# StackWalk64()

{% label %}StackWalk64.cpp{% endlabel %}
```cpp
	BOOL WINAPI StackWalk64(
	  __in      DWORD MachineType,
	  __in      HANDLE hProcess,
	  __in      HANDLE hThread,
	  __inout   LPSTACKFRAME64 StackFrame,
	  __inout   PVOID ContextRecord,
	  __in_opt  PREAD_PROCESS_MEMORY_ROUTINE64 ReadMemoryRoutine,
	  __in_opt  PFUNCTION_TABLE_ACCESS_ROUTINE64 FunctionTableAccessRoutine,
	  __in_opt  PGET_MODULE_BASE_ROUTINE64 GetModuleBaseRoutine,
	  __in_opt  PTRANSLATE_ADDRESS_ROUTINE64 TranslateAddress
	);
```
倒数第二个和倒数第三个函数指针可以直接调用Dbghelp.dll中的函数SymGetModuleBase64与SymFunctionTableAccess64。 倒数第四个ReadMemoryRoutine ，可以自己定义一个函数，主要调用ReadProcessMemory。这个函数主要得到STACKFRAME64这个栈帧。

然后通过栈帧的成员AddrPC的offset，可由函数**SymGetSymFromAddr64**得到符号信息，再通过**UnDecorateSymbolName（）**，**SymGetLineFromAddr64()**（）等函数得到具体的函数名，代码行等信息。