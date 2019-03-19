//#include "common.hpp"
/*
 * jd create at 2018-02-28
 * to build & run on Linux, just run :
 * make
 */
//#pragma once
#pragma warning(disable:4996)
#pragma warning(disable:4018)

#include <iostream>
#include <fstream>

#include <string>
#include <sstream>
#include <vector>
#include <stdint.h>  // uint64_t
#include <assert.h>

#include <vector>
#include <sstream>
#include <unordered_map>
#include <map>
#include <algorithm>    // std::sort
#include <utility>

#include <stack>
#include <memory.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <thread>
#include <mutex>
#include <cassert>

#include <nlohmann/json.hpp>

#if 0
//#if __linux__
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <htslib/faidx.h>
#include <strings.h>
#include <getopt.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include "htslib/tbx.h"
#include "htslib/sam.h"
#include "htslib/vcf.h"
#include "htslib/kseq.h"
#include "htslib/bgzf.h"
#include "htslib/hts.h"
#include "htslib/regidx.h"
#include <unordered_map>
#include <iomanip>
#include <list>
#include "hfile_internal.h"
#include <unistd.h>


#include "samtools.h"
#include "version.h"
#include <config.h>
#endif


#ifdef __linux__
#define __P__  return 0;   //__
#else
#define __P__  system("pause");return 0;   //__
#define popen(fp, fr) _popen((fp),(fr))
#define pclose(fp) _pclose(fp)
#define sleep(i) Sleep(1000*(i))

#endif
using namespace std;


#define DEL_ARR_MEM(P) if(NULL != (P)){delete [] (P); (P) = NULL;}






namespace ns {
	using json = nlohmann::json;

    // a simple struct to model a person
    struct person {
        std::string name;
        std::string address;
        int age;
    };

	void to_json(json& j, const person& p) {
		j = json{{"name", p.name}, {"address", p.address}, {"age", p.age}};
	}

	void from_json(const json& j, person& p) {
		j.at("name").get_to(p.name);
		j.at("address").get_to(p.address);
		j.at("age").get_to(p.age);
	}
};

// st__ main_
int main(int argc, char **argv)
{
	using json = nlohmann::json;

	json j;

	// add a number that is stored as double (note the implicit conversion of j to an object)
	j["pi"] = 3.141;

	// add a Boolean that is stored as bool
	j["happy"] = true;

	// add a string that is stored as std::string
	j["name"] = "Niels";

	// add another null object by passing nullptr
	j["nothing"] = nullptr;

	// add an object inside the object
	j["answer"]["everything"] = 42;

	// add an array that is stored as std::vector (using an initializer list)
	j["list"] = { 1, 0, 2 };

	// add another object (using an initializer list of pairs)
	j["object"] = { {"currency", "USD"}, {"value", 42.99} };

	// instead, you could also write (which looks very similar to the JSON above)
	json j2 = {
		{"pi", 3.141},
		{"happy", true},
		{"name", "Niels"},
		{"nothing", nullptr},
		{"answer", {
					   {"everything", 42}
				   }},
		{"list", {1, 0, 2}},
		{"object", {
					   {"currency", "USD"},
					   {"value", 42.99}
				   }}
	};


	auto j3 = R"(
  {
    "happy": true,
    "pi": 3.141
  }
)"_json;


		string s_j3 = j3.dump(4); 
	//cout << s_j3 << endl; 


	//cout << j2.dump(4) << endl; 

	json jj; 
	//cin >> jj; 
	//cout << jj << endl; // null 

	ifstream if_("./t/json.json"); 
	if_ >> jj ; 
	cout << jj << endl; 

	if_.close(); 

	ofstream of_("./t/json.json_new"); 
	of_ << jj.dump(4) << endl; 
	of_.close(); 


	json jj_; 
	jj_.push_back("foo");
	jj_.push_back(1);
	jj_.push_back(true);

	// also use emplace_back
	jj_.emplace_back(1.7888888);
	cout << jj_ << endl; 
	// iterate the array
	for (json::iterator it = jj_.begin(); it != jj_.end(); ++it) {
		std::cout << *it << '\n';
	}

	for(auto &e: jj_)
	{
		cout << e << endl; 	
	}

	cout << jj_[0] << endl; 

	json test =  R"(["foo",1, true, 1.7888888])"_json; 
	cout << test << endl; 
	assert( jj_ == test ); 

	cout << jj_.size() << endl; 
	cout << (jj_.empty() == 0) <<endl; 
	cout <<( jj_.type() == json::value_t::array)  << endl; 
	jj_.clear(); 
	jj_.empty(); 



	json t0;
	t0["a"] = "av"; 
	t0["a0"] = string("av0"); 
	t0["b"] = 33; 
	t0.emplace("key0", "value0"); 

	cout << (t0.count("key0") ==  1) << endl; 
	cout << (t0.count("key0____") ==  0) << endl; 

	cout << t0.dump(4)<<endl; 
	t0.erase("key0");
	cout << t0.dump(4)<<endl; 

	for (auto& k_v : t0.items()) {
		  std::cout << k_v.key() << " : " << k_v.value() << "\n";
	}

	vector<int> v_i(9,0xff); 
	json from_v(v_i); 
	for(auto& e: from_v)
	{
		//cout << e << endl; 
	}


	ns::person id_p {
		"Ned Flanders", "744 Evergreen Terrace", 60
	};


	//ns::to_json(from_struct, id_p); 
	json from_struct = id_p; 

	cout << from_struct.dump(4) << endl; 

	cout << 1 << endl; 	

	__P__;
}
