// ===========================================================================
// C++ Refresh Explorations
// ===========================================================================

#define USE_EXPERIMENTAL_ANY
//#define USE_BOOST_ANY

#define USE_EXPERIMENTAL_OPTIONAL
//#define USE_BOOST_OPTIONAL

//#define USE_EXPERIMENTAL_VARIANT
#define USE_BOOST_VARIANT

//#define USE_BOOST_REGEXP
// NOTE: if regular expressions from Boost are used, when compiling with g++ or
//	 clang++ you to specify the command line option`-lboost_regex`.

// ---------------------------------------------------------- General Includes
//
#include <algorithm>
#if !defined(USE_EXPERIMENTAL_ANY)\
 && !defined(USE_BOOST_ANY)
 #include <any>
#endif
#include <array>
#include <cassert>
#include <cmath>
#include <chrono>
#include <forward_list>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <memory>
#include <map>
#if !defined(USE_EXPERIMENTAL_OPTIONAL)\
 && !defined(USE_BOOST_OPTIONAL)
 #include <optional>
#endif
#if !defined(USE_BOOST_REGEXP)
 #include <regex>
#endif
#include <sstream>
#include <set>
#include <unordered_map>
#include <unordered_set>
#if !defined(USE_EXPERIMENTAL_VARIANT)\
 && !defined(USE_BOOST_VARIANT)
 #include <variant>
#endif
#include <vector>

// ------------------------------------------------------ Experimental Includes
//
#ifdef USE_EXPERIMENTAL_ANY
 #include <experimental/any>
#endif
#ifdef USE_EXPERIMENTAL_OPTIONAL
 #include <experimental/optional>
#endif
 #ifdef USE_EXPERIMENTAL_VARIANT
#include <experimental/variant>
#endif

// ------------------------------------------------------------- Boost Includes
//
#include <boost/type_index.hpp>

#ifdef USE_BOOST_ANY
 #include <boost/any.hpp>
#endif
#ifdef USE_BOOST_OPTIONAL
 #include <boost/optional.hpp>
#endif
#ifdef USE_BOOST_REGEXP
 #include <boost/regex.hpp>
#endif
#ifdef USE_BOOST_VARIANT
 #include <boost/variant.hpp>
#endif

// -------------------------------------------------------------- Helper Macros
//
#define PX(...)\
    (void)(std::cout << __func__ << '[' << __LINE__ << ']'\
                     << "\t" << #__VA_ARGS__ << " --> "\
		     << (__VA_ARGS__) << std::endl)
#define PT(...)\
    (void)(std::cout << __func__ << "[" << __LINE__ << ']'\
                     << "\t" #__VA_ARGS__ " --> "\
                     << boost::typeindex::type_id_with_cvr<__VA_ARGS__>()\
                     << std::endl)

// ----------------------------------------------------------------------------
//
//   :::::::::::::::
void helper_macros() {
//   :::::::::::::::

	const char greet[] = "hello, world";	PX(greet);
						PX(*greet);
						PX(greet[0]);
						PT(decltype(greet));
						PT(decltype(*greet));
	int x = 42;				PX(x);
						PX(x = 10);
						PX(++x);
						PX(x++);
						PX(x);
						PT(decltype(x));
						PT(decltype(x++));
						PT(decltype(++x));
	constexpr auto PI = 3.1415;		PX(PI);
						PT(decltype(PI));
						PT(decltype(&PI));
}

// ----------------------------------------------------------------------------
//
//   ::::::::::::::::::
void arithmetic_types() {
//   ::::::::::::::::::
	int i = -12;    	PX(i); PT(decltype(i));
	unsigned u = i;   	PX(u); PT(decltype(u));
//	short t{32768};   	PX(t); PT(dectlype(t));
	short t = 32768;   	PX(t); PT(decltype(t));
	char c = t+122;       	PX(c); PT(decltype(c));

	if (auto a = c)       {	PX(a); PT(decltype(a)); }
	if (auto a = u)       {	PX(a); PT(decltype(a)); }
	if (auto a = t)       {	PX(a); PT(decltype(a)); }
	if (auto a = c)       {	PX(a); PT(decltype(a)); }

	auto x = 3.1415L;	PX(x); PT(decltype(x));
	auto y = 1.4142L;	PX(y); PT(decltype(y));
}

// ----------------------------------------------------------------------------
//
//   ::::::::::::::::::::::
void brace_initialization() {
//   ::::::::::::::::::::::
	// TBD
}

// ----------------------------------------------------------------------------
//
//   ::::::::::::::::::::
void use_of_static_cast() {
//   ::::::::::::::::::::
	// TBD
}

// ----------------------------------------------------------------------------
//
//   :::::::::::::::::
void const_qualifier() {
//   :::::::::::::::::
	// TBD
}

// ----------------------------------------------------------------------------
//
void foo(short arr[]) {
	PX(arr); PT(decltype(arr)); PX(sizeof arr);
    // Note that a warning for this ---^^^^^^^^^^ is expected.
    // (To suppress it just use `-Wno-sizeof-array-argument`.)
}
void bar(short *p) {
	PX(p); PT(decltype(p)); PX(sizeof p);
}

//   :::::::::::::::::::::
void arrays_and_pointers() {
//   :::::::::::::::::::::
	void foo(short arr[]);
	void bar(short *p);

	short arr[10];	PX(sizeof arr); PX(sizeof(&arr));
	short i;	PX(sizeof i);   PX(sizeof(&i));

	foo(arr);
	bar(&i);
}

// ----------------------------------------------------------------------------
//
//   ::::::::::::::::::::
void address_arithmetic() {
//   ::::::::::::::::::::
	double data[20];		PX(sizeof data);
					PX(sizeof data[0]);
					PX(sizeof data[12]);
					PX(sizeof *data);
	char message[1024];		PX(sizeof message);
					PX(sizeof *message);
					PX(sizeof message[0]);
	int i = 1000;			PX(sizeof message[i]);

	double *dp = &data[0];		PX(dp);
					PX(&dp);
					PX(++dp);
	char *cptr = &message[i];	PX(cptr);
					PX(&cptr);
					PX(*(cptr-3));
	PX(data);		PX(&data);
	PT(decltype(data));	PT(decltype(&data));
	PX(data+1);     	PX(&data+1);
	double *(dataX[20]);	PT(decltype(dataX));
}

// ----------------------------------------------------------------------------
//
//   :::::::::::::::::::::::::
void equivalence_of_indexing() { // -------------------------------------------
//   :::::::::::::::::::::::::
	double data[20];	double *ptr = data; // = &data[0];
	PX(data);		PX(ptr);
	PT(decltype(data));	PT(decltype(ptr));
	PX(sizeof data);	PX(sizeof ptr);
	PT(decltype(data[0]));	PT(decltype(ptr[0]));
	PX(sizeof data[0]);	PX(sizeof ptr[0]);
	PX(sizeof *data);	PX(*ptr);
	PX(data+1);		PX(ptr+1);
	PX(&data+1);		PX(&ptr+1);

	PX(sizeof data / sizeof data[0]);
	PX(       (data+1) -         data);
	PX((char*)(data+1) - (char*) data);
	PX(       (&data+1) -        &data);
	PX((char*)(&data+1) - (char*)&data);

	const int N = 7; PX(N);
	PX(        ptr+N  -        ptr);
	PX((char*)(ptr+N) - (char*)ptr);
	PX(        &ptr[N]  -        &ptr[0]);
	PX((char*)(&ptr[N]) - (char*)&ptr[0]);
}

// ----------------------------------------------------------------------------
//
std::string array_of_int_to_string(int arr[], std::size_t sz) {
	std::ostringstream os;
	for (std::size_t i = 0; i < sz; ++i)
		os << arr[i] << "; ";
	return os.str();
}

//   ::::::::::::::::::::
void print_array_of_int() {
//   ::::::::::::::::::::
	int primes_table[] = {
	    2, 3, 5, 7, 11, 13, 17, 19, 23, 29
	};
	const auto N = sizeof primes_table / sizeof primes_table[0];
	PX(N);
	PX(array_of_int_to_string(primes_table, N));
}

// ----------------------------------------------------------------------------
//
class LimitCounter {
protected:
	const int start;
	const int limit;
	int ticks;
public:
	LimitCounter(int st, int lim)
		: start(st)
		, limit(lim)
		, ticks(st)
	{}
	virtual bool count() {
		if (++ticks > limit) {
			ticks = start;
			return true;
		}
		return false;
	}
	int value() const {
		return ticks;
	}
	void reset() {
		ticks = start;
	}
};

//   ::::::::::::::::::::
void limit_counter_demo() {
//   ::::::::::::::::::::
	LimitCounter lc1(1, 10);
        PX(lc1.value());
        lc1.count();
        PX(lc1.value());
        for (auto i = 0; i < 7; ++i) lc1.count();
        PX(lc1.value());
        for (auto i = 0; i < 4; ++i) lc1.count();
        PX(lc1.value());
        lc1.reset();
        PX(lc1.value());

 	LimitCounter lc2(0, 59);
        PX(lc2.value());
        lc2.count();
        PX(lc2.value());
        lc2.reset();
        PX(lc2.value());
}

// ----------------------------------------------------------------------------
//
class OverflowCounter : public LimitCounter {
	LimitCounter &next;
public:
	OverflowCounter(int st, int lim, LimitCounter& n)
		: LimitCounter(st, lim)
		, next(n)
	{}
	virtual bool count() {
		if (LimitCounter::count()) {
			next.count();
			return true;
		}
		return false;
	}
};

class OverflowCounter2 {
    const int start;
    const int limit;
    int ticks;
    OverflowCounter2 *pnext;
public:
    OverflowCounter2(int st, int lim, OverflowCounter2 *pn = nullptr)
        : start(st), limit(lim), ticks(st),  pnext(pn)
    {}
    void count() {
        if ((++ticks > limit) && (pnext != 0))
            pnext->count();
    }
    int value() const {
        return ticks;
    }
};

//   :::::::::::::::::::::::
void overflow_counter2_demo() {
//   :::::::::::::::::::::::
	OverflowCounter2 hours(0, 23);
	OverflowCounter2 minutes(0, 59, &hours);
	OverflowCounter2 seconds(0, 59, &minutes);
	PX(hours.value()); PX(minutes.value()); PX(seconds.value());
	for (auto i = 0; i < 22; ++i) seconds.count();
	PX(hours.value()); PX(minutes.value()); PX(seconds.value());
	for (auto i = 0; i < 60; ++i) seconds.count();
	PX(hours.value()); PX(minutes.value()); PX(seconds.value());
	for (auto i = 0; i < 3*60*60; ++i) seconds.count();
	PX(hours.value()); PX(minutes.value()); PX(seconds.value());
	for (auto i = 0; i < 24*60*60-21; ++i) seconds.count();
	PX(hours.value()); PX(minutes.value()); PX(seconds.value());
}

//   :::::::::::::::::::::::
void overflow_counter_demo() {
//   :::::::::::::::::::::::
	LimitCounter hours(0, 23);
	OverflowCounter minutes(0, 59, hours);
	OverflowCounter seconds(0, 59, minutes);
	PX(hours.value()); PX(minutes.value()); PX(seconds.value());
	for (auto i = 0; i < 22; ++i) seconds.count();
	PX(hours.value()); PX(minutes.value()); PX(seconds.value());
	for (auto i = 0; i < 60; ++i) seconds.count();
	PX(hours.value()); PX(minutes.value()); PX(seconds.value());
	for (auto i = 0; i < 3*60*60; ++i) seconds.count();
	PX(hours.value()); PX(minutes.value()); PX(seconds.value());
	for (auto i = 0; i < 24*60*60-21; ++i) seconds.count();
	PX(hours.value()); PX(minutes.value()); PX(seconds.value());
}

// ----------------------------------------------------------------------------
//
//   ::::::::::::::::::::::::::
void container_iterator_demo1() {
//   ::::::::::::::::::::::::::
	std::vector<int> data = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
	std::ostringstream all_data;
	for (std::vector<int>::iterator it = data.begin();
					it != data.end();
			              ++it)
		all_data << *it << "; ";
	PX(all_data.str());
}

//   ::::::::::::::::::::::::::
void container_iterator_demo2() {
//   ::::::::::::::::::::::::::
	std::vector<int> data = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
	std::ostringstream all_data;
	for (std::vector<int>::iterator it = data.begin() + 1;
					it < data.end() - 1;
			                it += 2)
		all_data << *it << "; ";
	PX(all_data.str());
}

//   ::::::::::::::::::::::::::
void container_iterator_demo3() {
//   ::::::::::::::::::::::::::
	std::vector<int> data = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
	std::string all_data;
	for (std::vector<int>::iterator it = data.begin();
					it != data.end();
			              ++it)
		all_data += (std::to_string(*it) + "; ");
	PX(all_data);
}

//   ::::::::::::::::::::::::::
void container_iterator_demo4() {
//   ::::::::::::::::::::::::::
//	std::vector<int> data =       { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
//	std::list<int> data =         { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
//	std::deque<int> data =        { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
//	std::vector<int> data =       { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
	std::array<int, 10> data =    { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
//	std::forward_list<int> data = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
	std::string all_data;
	for (auto it = data.begin(); it != data.end(); ++it)
		all_data += (std::to_string(*it) + "; ");
	PX(all_data);
}

//   ::::::::::::::::::::::::::
void container_iterator_demo5() {
//   ::::::::::::::::::::::::::
//                         duplicated value --------------v
//	std::vector<int> data =             { 2, 3, 5, 7, 2, 11, 13, 17, 19 };
//	std::set<int> data =                { 2, 3, 5, 7, 2, 11, 13, 17, 19 };
//	std::multiset<int> data =           { 2, 3, 5, 7, 2, 11, 13, 17, 19 };
//	std::unordered_set<int> data =      { 2, 3, 5, 7, 2, 11, 13, 17, 19 };
	std::unordered_multiset<int> data = { 2, 3, 5, 7, 2, 11, 13, 17, 19 };
	std::string all_data;
	for (auto it = data.begin(); it != data.end(); ++it)
		all_data += (std::to_string(*it) + "; ");
	PX(all_data);
}

// ----------------------------------------------------------------------------
//
//   :::::::::::::::::::::::::
void wordcount_demo_iterator() {
//   :::::::::::::::::::::::::
	std::map<std::string, int> words;
	std::string w;
	std::istringstream input("ist das der satz der dreimal der enthaelt "
				 "oder ist der satz das nicht");
	while (input >> w)
		++words[w];
	std::ostringstream output;
	for (auto it = words.cbegin(); it != words.cend(); ++it)
		output << it->first << ':' << it->second << ' ';
	PX(output.str());
}

//   :::::::::::::::::::::::::
void wordcount_demo_rangefor() {
//   :::::::::::::::::::::::::
	std::map<std::string, int> words;
	std::string w;
	std::istringstream input("ist das der satz der dreimal der enthaelt "
				 "oder ist der satz das nicht");
	while (input >> w)
		++words[w];
	std::ostringstream output;
	for (const auto &e : words)
		output << e.first << ':' << e.second << ' ';
	PX(output.str());
}

//   ::::::::::::::::
void sort_algo_demo() {
//   ::::::::::::::::
	std::vector<int> data = { 2, 3, 5, 7, 2, 11, 13, 17, 19, 23, 29 };
//	sort(data.begin(), data.end());
	std::sort(data.begin(), data.end(), [](int a, int b) { return (a > b); });
	std::ostringstream output;
	for (auto e : data)
		output << e << "; ";
	PX(output.str());
}

// ----------------------------------------------------------------------------
//
template<typename InIt, typename OutIt, typename Pred>
OutIt filter(InIt from, InIt upto, OutIt dest, Pred pred) {
    while (from != upto) {
        if (pred(*from))
            *dest++ = *from;
        ++from;
    }
    return dest;
}

bool gt_zero(int x) { return (x > 0); }
bool is_even(int x) { return ((x % 2) == 0); }
class is_even_check {
public: bool operator()(int x) const { return ((x % 2) == 0); }
};
class is_divisable_by {
	const int divisor;
public:	is_divisable_by(int d) : divisor(d) {}
	bool operator()(int x) const { return ((x % divisor) == 0); }
};

//   ::::::::::::::
void filter_demo1() {
//   ::::::::::::::
	std::vector<int> data = { 2, 3, -7, 2, 12, -4, 8, -17, 22 };
	int result[20];
	int *filled = &result[0];
//	filled = filter(data.begin(), data.end(), filled, gt_zero);
  	filled = filter(data.begin(), data.end(), filled, is_even);
//  	filled = filter(data.begin(), data.end(), filled, is_even_check{});
//  	filled = filter(data.begin(), data.end(), filled, is_divisable_by{2});
//  	filled = filter(data.begin(), data.end(), filled, is_divisable_by{3});
	std::ostringstream output;
	for (auto p = &result[0]; p < filled; ++p)
		output << *p << ' ';
	PX(output.str());
}

//   ::::::::::::::
void filter_demo2() {
//   ::::::::::::::
	std::vector<int> data = { 2, 3, -7, 2, 12, -4, 8, -17, 22 };
	std::vector<int> result;
	filter(data.begin(), data.end(),  // <----- input
	       std::back_inserter(result), // <---- output (append to vector)
	       gt_zero // <------------------------ predicate (function)
//	       [](int x) { return (x > 0); } // <-- predicate (lambda)
	);
	std::ostringstream os;
	for (auto e : result)
		os << e << ' ';
	PX(os.str());
}

//   ::::::::::::::
void filter_demo3() {
//   ::::::::::::::
	std::vector<int> data = { 2, 3, -7, 2, 12, -4, 8, -17, 22 };
	std::ostringstream os;
	filter(data.begin(), data.end(), // <------------- input
	       std::ostream_iterator<int>(os, " "), // <-- output (to stream)
	       gt_zero // <------------------------------- predicate (function)
//	       is_even // <------------------------------- predicate (function)
//	       is_even_checker{} // <--------------------- predicate (functor)
//	       is_divisable_by{2} // <-------------------- predicate (functor)
//	       is_divisable_by{3} // <-------------------- predicate (functor)
//             [](int x) { return ((x % 3) == 0); } // <-- predicate (lambda) 
	);
	PX(os.str());
}

// ----------------------------------------------------------------------------
//
//   :::::::::::::
void regexp_demo() {
//   :::::::::::::
#if !defined(USE_BOOST_REGEXP)
	using std::regex;
	using std::regex_match;
	using std::regex_replace;
	using std::smatch;
#else
	using boost::regex;
	using boost::regex_match;
	using boost::regex_replace;
	using boost::smatch;
#endif
	auto euro_parser = [](const std::string& str, double& ec) {
    		regex re{R"(([1-9]\d{0,2}(?:\.\d{3})*),(\d{2}))"};
 // 		regex re{R"((0|[1-9]\d{0,2})(?:\.\d{3})*,(\d{2}))"};
		smatch m;
		if (!regex_match(str, m, re))
			return false;
		const std::string es{m[1].str()};
		ec = std::stod(regex_replace(es, regex{"\\."}, ""))
		   + std::stod(m[2].str())/100.0;
		return true;
	};

	double amount;
	PX(euro_parser("1,23", amount));	PX(amount);
	PX(euro_parser("1.234,56", amount));	PX(amount);
	PX(euro_parser("0,60", amount));	PX(amount);
}

// ----------------------------------------------------------------------------
//
#if 0
int roll_dice() {
	static std::default_random_engine random_roll{};
	static std::uniform_int_distribution<int> one_to_six{1, 6};
	return one_to_six(random_roll);
}

//   ::::::::::::::::
void roll_dice_demo() {
//   ::::::::::::::::
	std::ostringstream os;
	std::generate_n(std::ostream_iterator<int>(os, " "), 10, roll_dice);
	PX(os.str());
}
#endif

// ----------------------------------------------------------------------------
//
void tuple_demo() {
	auto euro_parser = [](const std::string& str) {
		#if !defined(USE_BOOST_REGEXP)
		namespace rx =  std;
		#else
		namespace rx = boost;
		#endif
		rx::regex re{R"((0|[1-9]\d{0,2}(?:\.\d{3})*),(\d{2})|-)"};
		rx::smatch m;
		if (!rx::regex_match(str, m, re))
			return std::make_tuple(false, 0.L);
		const auto es = rx::regex_replace(m[1].str(), rx::regex{"\\."}, "");
		const auto ec = rx::regex_replace(m[2].str(), rx::regex{"^-$"}, "0");
		return std::make_tuple(true, std::stold(es) + std::stold(ec)/100);
	};
	auto result = euro_parser("1,23");	PX(std::get<0>(result));
						PX(std::get<1>(result));
	result = euro_parser("1.234,56");	PX(std::get<bool>(result));
						PX(std::get<long double>(result));
	bool success;
	long double euro;
	PX(std::tie(success, euro) = euro_parser("0,60"), success); PX(euro);
	PX(std::tie(success, std::ignore) = euro_parser("0,S3"), success);
	PX(std::tie(success, std::ignore) = euro_parser("0,53"), success);
}


// ----------------------------------------------------------------------------
//
#if !defined(USE_EXPERIMENTAL_OPTIONAL)\
 && !defined(USE_BOOST_OPTIONAL)
	template<typename T>
	using std_boost_optional = std::optional<T>;
#elif defined(USE_EXPERIMENTAL_OPTIONAL)
	template<typename T>
	using std_boost_optional = std::experimental::optional<T>;
#elif defined(USE_BOOST_OPTIONAL)
	template<typename T>
	using std_boost_optional = boost::optional<T>;
#endif

//   ::::::::::::::::::::::
void std_or_boost_optional1() {
//   ::::::::::::::::::::::
	auto euro_parser = [](const std::string& str)
				-> std_boost_optional<double> {
		#if !defined(USE_BOOST_REGEXP)
		namespace rx =  std;
		#else
		namespace rx = boost;
		#endif
		rx::regex re{R"(0|([1-9]\d{0,2}(?:\.\d{3})*),(\d{2}))"};
		rx::smatch m;
		if (!rx::regex_match(str, m, re))
			return {};
		const auto es{m[1].str()};
		return std::stod(rx::regex_replace(es, rx::regex{"\\."}, ""))
	 	     + std::stod(m[2].str())/100.0;
	};
	auto result = euro_parser("1,23");	PX((bool)result);
						PX(result.value());
	if (auto tmp = euro_parser("1.234,56"))	PX(tmp.value());
	if (auto tmp = euro_parser("12.34,56"))	PX(tmp.value());

	PX(euro_parser("0.S3").value_or(0.99));
	PX(euro_parser("0.53").value_or(0.99));

	std_boost_optional<double> tmp;			  PX(bool(tmp));
	PX(static_cast<bool>(tmp = euro_parser("0.S3"))); PX(bool(tmp));
	PX(static_cast<bool>(tmp = euro_parser("0.53"))); PX(bool(tmp));
						       // PX(bool{tmp});
#if !defined(USE_BOOST_OPTIONAL)\
 && !defined(USE_EXPERIMENTAL_OPTIONAL)
				PX(euro_parser("0.53").has_value());
				PX(euro_parser("0.S3").has_value());
#endif
}

//   ::::::::::::::::::::::
void std_or_boost_optional2() {
//   ::::::::::::::::::::::
	auto euro_parser = [](const std::string& str,
		              std_boost_optional<double>& result) {
		#if !defined(USE_BOOST_REGEXP)
		using std::regex;
		using std::smatch;
		using std::regex_match;
		using std::regex_replace;
		#else
		using boost::regex;
		using boost::smatch;
		using boost::regex_match;
		using boost::regex_replace;
		#endif
		regex re{R"(0|([1-9]\d{0,2}(?:\.\d{3})*),(\d{2}))"};
		smatch m;
		if (!regex_match(str, m, re)) return;
		const auto es{m[1].str()};
		result = std::stod(regex_replace(es, regex{"\\."}, ""))
		       + std::stod(m[2].str())/100.0;
	};
	std_boost_optional<double> euro;
	euro_parser("1.234,50", euro);	if (euro) PX(euro.value());
#if defined(USE_EXPERIMENTAL_OPTIONAL)
	euro = std::experimental::nullopt;
#else
	euro.reset();
#endif
	euro_parser("1.234,5", euro);	if (euro) PX(euro.value());
}

// ----------------------------------------------------------------------------
//
//   ::::::::::::::::::
void std_or_boost_any() {
//   ::::::::::::::::::
#if !defined(USE_EXPERIMENTAL_ANY)\
 && !defined(USE_BOOST_ANY)
	using any_t = std::any;
#elif defined(USE_EXPERIMENTAL_ANY)
	using any_t = std::experimental::any;
#elif defined(USE_BOOST_ANY)
	using any_t = boost::any;
#endif
	std::vector<any_t> v;

	#ifdef USE_STD_LITERAL_SUFFIXES
	using namespace std::string_literals;
	v.emplace_back("hello, world"s);
	#else
	v.emplace_back(std::string{"hello, world"});
	#endif
	v.emplace_back(true);
	v.emplace_back(42);
	v.emplace_back(2*std::acos(0.0));
	v.emplace_back(!true);
	v.emplace_back("hello, world");

#if !defined(USE_EXPERIMENTAL_ANY)\
 && !defined(USE_BOOST_ANY)
        for (const auto& e : v) {
                if (const auto p = std::any_cast<bool>(&e)) {
                        PX(*p);
                        continue;
                }
                if (const auto p = std::any_cast<int>(&e)) {
                        PX(*p);
                        continue;
                }
                if (const auto p = std::any_cast<double>(&e)) {
                        PX(*p);
                        continue;
                }
                if (const auto p = std::any_cast<std::string>(&e)) {
                        PX(*p);
                        continue;
                }
        }
#elif defined(USE_EXPERIMENTAL_ANY)
        for (const auto& e : v) {
                if (const auto p = std::experimental::any_cast<bool>(&e)) {
                        PX(*p);
                        continue;
                }
                if (const auto p = std::experimental::any_cast<int>(&e)) {
                        PX(*p);
                        continue;
                }
                if (const auto p = std::experimental::any_cast<double>(&e)) {
                        PX(*p);
                        continue;
                }
                if (const auto p = std::experimental::any_cast<std::string>(&e)) {
                        PX(*p);
                        continue;
                }
        }
#elif defined(USE_BOOST_ANY)
        for (const auto& e : v) {
                if (const auto p = boost::any_cast<bool>(&e)) {
                        PX(*p);
                        continue;
                }
                if (const auto p = boost::any_cast<int>(&e)) {
                        PX(*p);
                        continue;
                }
                if (const auto p = boost::any_cast<double>(&e)) {
                        PX(*p);
                        continue;
                }
                if (const auto p = boost::any_cast<std::string>(&e)) {
                        PX(*p);
                        continue;
                }
	}
#endif
}

// ----------------------------------------------------------------------------
//
#ifndef USE_BOOST_VARIANT
struct variant_t_printer {
        #if 1
        void operator()(bool bool_arg) const {
                PX(bool_arg);
        }
        void operator()(int int_arg) const {
                PX(int_arg);
        }
        void operator()(double double_arg) const {
                PX(double_arg);
        }
        void operator()(const std::string& string_arg) const {
                PX(string_arg);
        }
        #else
        template<typename T>
        void operator()(const T& arg) const {
                PX(arg);
        }
        #endif
#else
struct variant_t_printer : boost::static_visitor<> {
	#if 0
	void operator()(bool bool_arg) const {
		PX(bool_arg);
	}
	void operator()(int int_arg) const {
		PX(int_arg);
	}
	void operator()(double double_arg) const {
		PX(double_arg);
	}
	void operator()(const std::string& string_arg) const {
		PX(string_arg);
	}
	#else
	template<typename T>
	void operator()(const T& arg) const {
		PX(arg);
	}
	#endif
};
#endif

//   :::::::::::::::::::
void std_or_boost_variant() {
//   :::::::::::::::::::
#ifndef USE_BOOST_VARIANT
	using variant_t = std::variant<bool, int, double, std::string>;
#else
	using variant_t = boost::variant<bool, int, double, std::string>;
#endif
	std::vector<variant_t> v;

	#ifdef USE_STD_LITERAL_SUFFIXES
	using namespace std::string_literals;
	v.emplace_back("hello, world"s);
	#else
	v.emplace_back(std::string{"hello, world"});
	#endif
	v.emplace_back(true);
	v.emplace_back(42);
	v.emplace_back(2*std::acos(0.0));
	v.emplace_back(!true);
	v.emplace_back("hello, world");

#ifndef USE_BOOST_VARIANT
        for (const auto& e : v) {
                if (const auto p = std::get_if<bool>(&e)) {
                        PX(*p);
                        continue;
                }
                if (const auto p = std::get_if<int>(&e)) {
                        PX(*p);
                        continue;
                }
                if (const auto p = std::get_if<double>(&e)) {
                        PX(*p);
                        continue;
                }
                if (const auto p = std::get_if<std::string>(&e)) {
                        PX(*p);
                        continue;
                }
        }
        while (!v.empty()) {
                std::visit(variant_t_printer{}, v.back());
                v.pop_back();
        }
#else
	for (const auto& e : v) {
		if (const auto p = boost::get<bool>(&e)) {
			PX(*p);
			continue;
		}
		if (const auto p = boost::get<int>(&e)) {
			PX(*p);
			continue;
		}
		if (const auto p = boost::get<double>(&e)) {
			PX(*p);
			continue;
		}
		if (const auto p = boost::get<std::string>(&e)) {
			PX(*p);
			continue;
		}
	}
	while (!v.empty()) {
		boost::apply_visitor(variant_t_printer(), v.back());
		v.pop_back();
	}
#endif
}

// --------------------------------------------------------------- Main Program
//
int main() {
	std::cout.setf(std::ios::boolalpha);
//	helper_macros();

//	arithmetic_types();
//	brace_initialization();
//	use_of_static_cast();
//	const_qualifier();
//	arrays_and_pointers();
//	address_arithmetic();
//	equivalence_of_indexing();
//	print_array_of_int();

//	limit_counter_demo();
//	overflow_counter_demo();
//	overflow_counter2_demo();

//	container_iterator_demo1()
//	container_iterator_demo2()
//	container_iterator_demo3()
//	container_iterator_demo4()
//	container_iterator_demo5()

//	wordcount_demo_iterator();
//	wordcount_demo_rangefor();

//	sort_algo_demo();

//	filter_demo1();
//	filter_demo2();
//	filter_demo3();

//	roll_dice_demo();
//	regexp_demo();
//  	tuple_demo();

// 	std_or_boost_optional1();
//	std_or_boost_optional2();
//	std_or_boost_any();
//  	std_or_boost_variant();
}
