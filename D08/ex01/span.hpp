#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <exception>

class Span {

    private:
        unsigned int    _N;
        std::vector<int>  _vec;
        Span(void);

    public:
        Span(unsigned int N);
        Span(Span const & src);
        virtual ~Span(void);

        Span &      operator=(Span const & rhs);

        unsigned int        getN(void) const;
        std::vector<int>     getVec(void) const;
        void                addNumber(int);
        long                shortestSpan(void) const;
        long                longestSpan(void) const;

};

#endif