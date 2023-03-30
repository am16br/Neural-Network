#include "yfapi.hpp"
using namespace std;
int main(int argc, char* argv[])
{
    yfapi::YahooFinanceAPI api;
    datatable::DataTable <float> dt = api.get_ticker_data("spy", "2020-09-01", "2020-10-06");
    // datetime not supported in DataTables (https://github.com/anthonymorast/DataTables/issues/5)
    dt.drop_columns(new string[1]{"Date"}, 1);
    dt.print_shape(cout);
    dt.print_headers(cout);
    api.download_ticker_data("qqq", "2020-01-01", "2020-10-07");
    api.set_interval(MONTHLY);
    datatable::DataTable<float> dt2 = api.get_ticker_data("aapl", "2010-01-01", "2020-10-01", true);
    return 0;
}
