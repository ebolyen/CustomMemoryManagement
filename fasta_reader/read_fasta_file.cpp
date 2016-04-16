#include <iostream>
#include <fstream>


struct FastaFileRecord {
  char *sequence;
  char *header;
}record;


int main( int argc, char **argv ){
    int mer_len = argv[2];

    if( argc <= 1 ){
        std::cerr << "Usage: "<<argv[0]<<" [infile]" << std::endl;
        return -1;
    }

    std::ifstream input(argv[1]);
    if(!input.good()){
        std::cerr << "Error opening '"<<argv[1]<<"'. Bailing out." << std::endl;
        return -1;
    }

    std::string line, name, content;
    while( std::getline( input, line ).good() ){
        if( line.empty() || line[0] == '>' ){ // Identifier marker
            if( !name.empty() ){ // Print out what we read from the last entry
                std::cout << name << " : " << content << std::endl;
                struct FastaFileRecord * new_record;
                new_record = malloc(sizeof(struct FastaFileRecord));
                new_record -> header = name; // adding header to struct
                name.clear();
            }
            if( !line.empty() ){
                name = line.substr(1);
            }
            char[mer_len] seq;
            strcpy(seq, content.c_str()); // adding sequence to struct
            FastaFileRecord -> sequence = seq;
            content.clear();
        } else if( !name.empty() ){
            if( line.find(' ') != std::string::npos ){ // Invalid sequence--no spaces allowed
                name.clear();
                content.clear();
            } else {
                content += line;
            }
        }
    }
    if( !name.empty() ){ // Print out what we read from the last entry
        std::cout << name << " : " << content << std::endl;
    }

    return 0;
}
