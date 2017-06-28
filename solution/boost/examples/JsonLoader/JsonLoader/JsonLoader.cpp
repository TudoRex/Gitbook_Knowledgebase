// JsonLoader.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cassert>

#include "json11.hpp"
#include "ThostFtdcUserApiStruct.h"
#include <boost/fusion/adapted.hpp>
#include <boost/fusion/view.hpp>
#include <boost/fusion/container.hpp>
#include <boost/fusion/algorithm.hpp>

using namespace std;
using namespace json11;
namespace fusion = boost::fusion;

void LoadJson(string& out, const char* path)
{
	ifstream ifs(path);
	assert(ifs.is_open());

	string linetmp;
	stringstream ss;
	ss.clear();
	ss.str("");
	while (std::getline(ifs, linetmp))
	{
		ss << linetmp;
	}
	std::swap(out, ss.str());
}

namespace keys
{
	struct ufx_dict_1;
	struct ufx_dict_2;
}

#include <string>

struct MyUserLogin
{
	std::string UserID;
	double		Password;
};

BOOST_FUSION_ADAPT_ASSOC_STRUCT(
	::MyUserLogin,
	(UserID, keys::ufx_dict_1)
	(Password, keys::ufx_dict_2)
)

enum KeyIndex : unsigned 
{
	ufx_dict_1,
	ufx_dict_2
};



struct MapVisitor
{
	template<typename T>
	void operator() (const T& t) const
	{
		std::cout << "{" <<typeid(T).name()<< "}" << std::endl;
		std::cout << "first type:{ "<< typeid(T::first_type).name() <<"}"<< std::endl;
		std::cout << "second type:{" << typeid(T::second_type).name() <<"}"<< std::endl;
	}

	template<typename V>
	void operator() (const fusion::pair<V, double>& p) const
	{
		std::cout << " [Value = double]" << std::endl;

	}
};



int main()
{
	string jsonbuf;
	LoadJson(jsonbuf, "ufx.json");

	//cout << jsonbuf << endl;

	string err;
	const auto json = Json::parse(jsonbuf, err);
	//cout << json["$NewOrder"].string_value() << endl;
	auto packet = json["$NewOrder"];

	MyUserLogin field;

	fusion::for_each(fusion::as_map(field), MapVisitor());
	

    return 0;
}

