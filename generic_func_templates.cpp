

/* Return the size of an array */
template<typename T, size_t N>
constexpr size_t numel(T (&)[N]) // 'constexpr' needed if this function's is used for e.g  "int b[numel(a)] = {0};"
{ 
	return N; 
}

/* Example of taking an array of N elements of type T as function parameter */
template<typename T, size_t N>
void reverse(T (&arr)[N])
{
    for (size_t i = 0; i < N/2; ++i)
    {
        T tmp = arr[i];
        arr[i] = arr[N-1-i];
        arr[N-1-i] = tmp;
    }
}

/* Print each element in a native array */
template<typename T, size_t N>
void printArr(const T (&arr)[N])
{
    for (size_t i = 0; i<N; ++i)
    {
        std::cout << arr[i];
        if (i == N-1) std::cout << std::endl;
        else std::cout << ", ";
    }    
}

/* Print each element in an STL vector*/
template<typename T>
void printVec(std::vector<T> vec)
{
    for (const auto &el : vec)
    {
        std::cout << el;
        if (el == vec.back()) std::cout << endl;
        else std::cout << ", ";
    }
}

 