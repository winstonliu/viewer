#include "imgsource.h"
#include <iomanip>

#define TEST

#ifdef TEST
#define PREFIX "test/prv"
#else
#define PREFIX "transfer/img"
#endif

class FileSource: public ImageSource {

	public: 
		FileSource();
		FileSource(int num);
		~FileSource();	
		
		bool getImage(std::vector<unsigned char> &data);
	
	private:
		int i, n;
};
