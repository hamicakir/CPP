class Pi
{
    public:
        Pi (const int nTerms);
        double apprErr();
        //uses value() function’s return and value of actual PI, returns approximation error.
        void print(); // //uses value() function’s return displays it
    private:
        int n;
        double value(); // return value of pi with assigned number of terms
};