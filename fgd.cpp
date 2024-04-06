#include <iterator>
using namespace std;
template <typename _RandomAccessIterator>
inline void
stable_sort(_RandomAccessIterator __first, _RandomAccessIterator __last)
{
    // concept requirements
    __glibcxx_function_requires(_Mutable_RandomAccessIteratorConcept<
                                _RandomAccessIterator>)
        __glibcxx_function_requires(_LessThanComparableConcept<
                                    typename iterator_traits<_RandomAccessIterator>::value_type>)
            __glibcxx_requires_valid_range(__first, __last);

    _GLIBCXX_STD_A::__stable_sort(__first, __last,
                                  __gnu_cxx::__ops::__iter_less_iter());
}