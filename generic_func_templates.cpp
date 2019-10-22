

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

/* Print bits in arbitrary datatype (little endian) */
void printBits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;

    for (i=size-1;i>=0;i--)
    {
        for (j=7;j>=0;j--)
        {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
    }
    puts("");
}

/*
*   Prints the contents of a vector, separated by spaces.
*   A newline is printed after the end of the vector
*
*   #include <vector> and <iostream>
*/
template<typename T>
void vecPrint(const std::vector<T> &vec)
{
    for (auto el : vec)
    {
        std::cout << el << " ";        
    }
    
    std::cout << std::endl;
}


/* 
*   Swaps two subranges of a std::vector
*
*   Make sure start1 < stop1 < start2 < stop2
*
*   #include <vector> and <algorithm>
*/
template<typename T>
void subswap(std::vector<T> &v, const int &start1, const int &stop1, const int &start2, const int &stop2)
{ 
    int len1    = stop1 - start1 + 1;
    int len2    = stop2 - start2 + 1;    
    auto first  = v.begin() + start1;
    auto last   = v.begin() + stop2 + 1; 
    
    std::rotate(first, v.begin()+start2, last);             // L-Rotate the affected interval to begin with segment 2:                      [XXXXXAAAAYYYBB] -> [XXXXXBBAAAAYYY]
    std::rotate(first+len2, first+len2+len1, last);         // L-Rotate the truncated interval to begin with whatever came after segment 1: [XXXXXBBAAAAYYY] -> [XXXXXBBYYYAAAA]  
}

 