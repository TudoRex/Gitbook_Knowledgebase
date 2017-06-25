// t2sdk_fusion.cpp : 定义控制台应用程序的入口点。
//
//#include <boost/fusion/adapted/struct/define_assoc_struct.hpp>
#include <boost/fusion/include/define_assoc_struct.hpp>
//#include <boost/fusion/adapted/adt/adapt_adt.hpp>
#include <boost/fusion/include/adapt_adt.hpp>

#include <boost/fusion/include/front.hpp>
#include <boost/fusion/include/back.hpp>
#include <boost/fusion/include/key_of.hpp>
#include <boost/fusion/include/begin.hpp>

#include <iostream>
#include <string>

#include "stdafx.h"
namespace fusion = boost::fusion;
using namespace std;

namespace keys
{
	struct name;
	struct age;
	struct money;
}

// demo::employee is a Fusion sequence
BOOST_FUSION_DEFINE_ASSOC_STRUCT(
	(demo), employee,
	(std::string, name, keys::name)
	(int, age, keys::age)
	(double, money, keys::name)
)

int _tmain(int argc, _TCHAR* argv[])
{
	demo::employee e("amao", 18, 1000.0);

	cout << fusion::front(e) << endl;
	cout << fusion::back(e) << endl;

// 	typedef fusion::result_of::begin<demo::employee> type_begin;
// 
// 	//BOOST_MPL_ASSERT((boost::is_same<fusion::result_of::key_of<type_begin>::type, keys::name>));
// 	BOOST_MPL_ASSERT((boost::is_same<fusion::result_of::key_of<type_begin>::type, std::string>));

	/*typedef fusion::map<fusion::pair<float, int> > vec;*/
	typedef fusion::result_of::begin<demo::employee>::type first;

	BOOST_MPL_ASSERT((boost::is_same<fusion::result_of::key_of<first>::type, keys::name>));
	//BOOST_STATIC_ASSERT(boost::is_same<fusion::result_of::key_of<first>::type, std::string>);


	return 0;
}

