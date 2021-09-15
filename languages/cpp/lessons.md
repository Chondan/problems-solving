# Lesson Learned 07 JUNE 2021

- [C - Avoiding warning "address of stack memory associated with local variable returned"](https://www.debugcn.com/en/article/51285870.html)
	- The life time of `local` variable ends immediately when the function call 
	is complete. After that point any pointers to `local` variable are invalidated
	and cannot be used.
	- The compiler uses stack memory to store local variables, and the warning indicates that you're returning an address to a now-invalidated stack variable.
	- Solutions
		1. The only way to work around this is to allocate memory dynamically and return that.
		2. You can also use `static` to extend the lifetime of `local` variable. Though this is not without consequences, either, as now `local` variable is shared, not unique to each function call.
- [Static Keyword in C++](https://www.geeksforgeeks.org/static-keyword-cpp/)
- [Const keyword in c++](https://www.geeksforgeeks.org/const-keyword-in-cpp/)
- [Templates in C++](https://www.geeksforgeeks.org/templates-cpp/)