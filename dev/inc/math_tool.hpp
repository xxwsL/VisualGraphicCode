#pragma once
#ifndef _math_tool_hpp_
#define _math_tool_hpp_

#ifndef self_pi
#define self_pi 3.1415926
#endif

#include <iosfwd>
#include <string>

namespace MathTool {
	/*_________________________function___________________________*/
	//Êı×Ö×ª×Ö·û´®
	//number : ÊäÈëÊı×Ö
	template<typename T> static std::string num_str(const T& numbers_) {
		std::string re_str;
		std::stringstream stream;
		stream << numbers_;
		stream >> re_str;
		return re_str;
	}

	//×Ö·û´®×ª×Ö·û
	//str : ×Ö·û´®
	template<typename T> static T str_num(const std::string& str_) {
		T re_num = 0;
		std::stringstream stream(str_);
		stream >> re_num;
		return re_num;
	}
};

#endif // _math_par_h_
