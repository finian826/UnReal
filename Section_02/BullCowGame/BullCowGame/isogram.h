#pragma once
#ifndef __ISOGRAM__
#define __ISOGRAM__
#include <map>
#ifndef TMAP
#define TMap std::map
#endif // !TMAP

using int32 = int;
using FString = std::string;
using FText = std::string;

class Isogram
{ 
public:
	bool IsIsogram(FString) const;

private:

};
#endif // !__ISOGRAM__
