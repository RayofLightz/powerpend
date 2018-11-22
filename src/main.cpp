//main.cpp
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

vector<string> power_pend_vecotrs(vector<string> vec_one, vector<string> vec_two){
        //Iterate over the vectors and add each element together
        vector<string> return_val;
        vector<string>::iterator vec_it;
        vector<string>::iterator vec2_it;
        for(vec_it = vec_one.begin(); vec_it != vec_one.end(); vec_it++){
                for(vec2_it = vec_two.begin(); vec2_it != vec_two.end(); vec2_it++){
                        string a = *vec_it + *vec2_it;
                        return_val.push_back(a);
                }
        }
        return return_val;
}

int main(int argc, char *argv[]){
        if(argc < 2){
                cout << "Powerpend" << "v0.1" << endl;
                cout << "Usage powerpend <file_one> <file_two> <output-defaults to stdout>" << endl;
                return 0;
        }
        ifstream input1;
        ifstream input2;
        //the stream to use for output
        //allows for defaulting to stdout if no out file is specified
        streambuf *outstream;
        input1.open(argv[1]);
        input2.open(argv[2]);
        ofstream fout;
        //Sets the outstream to be either cout or a file
        if(argc == 4){
                fout.open(argv[3]);
                outstream = fout.rdbuf();
        }
        else
                outstream = cout.rdbuf();
        //Create a ostream using the ouput stream created and set above
        ostream output(outstream);

        //Read input1 and input2 into two vectors
        vector<string> input1_vec;
        vector<string> input2_vec;
        string line;
        while(getline(input1,line)){
                input1_vec.push_back(line);
        }
        while(getline(input2,line)){
                input2_vec.push_back(line);
        }
        //vector iterators
        vector<string> end_vec = power_pend_vecotrs(input1_vec,input2_vec);
        vector<string>::iterator final_vec_it;
        for(final_vec_it = end_vec.begin(); final_vec_it != end_vec.end(); final_vec_it++){
                output << *final_vec_it << endl;
        }
        //clean up
        input1.close();
        input2.close();
        fout.close();
        return 0;
}

