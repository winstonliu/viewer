#include "filesource.h"


FileSource::FileSource(){
	i = 0; 
	n = 5;
}

FileSource::FileSource(int num){
	i = 0;
	n = num;
}

FileSource::~FileSource(){}	
		
bool FileSource::getImage(std::vector<unsigned char> &imgdata){
	if (i==n)
		return false;
	
	std::ifstream ifs;
	std::stringstream ss;
	ss<<PREFIX;
	ss<<std::setfill('0')<<std::setw(4)<<++i;
	ss<<".jpg";
	std::string filename = ss.str();
	ifs.open(filename, std::ifstream::binary);

	if(ifs) {
		ifs.seekg(0,ifs.end);
		std::streampos size = ifs.tellg();
		imgdata.resize(size);

		ifs.seekg(0,ifs.beg);
		ifs.read((char*)&imgdata[0],size);
		ifs.close();
		return true;
	}

	return false;
}
	
