import random 
import os
import sys


def randomword(length):
   s = ""
   for i in range(length):
       a = random.randint(97, 122)
       s += chr(a)
   return s

def replace(original_string, string_to_replace):
    result_string = ""
    while original_string.find(string_to_replace) >= 0:
      pos = original_string.find(string_to_replace)
      result_string += original_string[0: pos]
      result_string += randomword(40)
      next_pos = pos+2
      original_string = original_string[next_pos:]
    result_string += original_string[:]
    return result_string

junk = """
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class {} {
public:
int {};
int {};
int {};
int {}();
string {}(int {}, int {}, int {});
double {}();
string {}(int {}, double {});
double {}(double {}, int {}, string {});
string {}(int {}, bool {}, string {}, string {}, double {}, double {}, string {}, bool {});

protected:
double {};

void {}(bool {}, double {}, bool {}, double {}, int {}, int {});
void {}(bool {}, double {}, int {}, int {}, bool {}, double {}, int {});
int {}();
int {}(int {}, double {}, int {}, string {}, string {}, int {}, string {}, double {}, bool {}, bool {});
double {}(int {}, string {}, int {}, double {});
bool {}(int {});
bool {}(string {}, double {}, bool {}, string {}, int {}, int {}, double {}, bool {}, double {});
void {}(double {}, int {}, int {}, string {}, double {}, double {});

private:
int {};
int {};

double {}(bool {}, double {});

};




void {}(bool {}, double {}, bool {}, double {}, int {}, int {}) {

}

void {}(bool {}, double {}, int {}, int {}, bool {}, double {}, int {}) {
int {} = 8745;
int {} = 4532;
bool {} = true;
bool {} = false;
int {} = 2342;
double {} = 6576;
int {} = 1234;
int {} = 3345;
string {} = "{}";
int {} = 4565;
if (string("{}") != string("{}")) {
int {}; 
}

}
"""

file_name = raw_input("Enter the EXACT path to your .cpp files:")

def add_junk():
   for root, dirs, files in os.walk(file_name):
      for file in files:
         if file.endswith(".cpp"):
            stra = replace(junk, "{}")
            with open(os.path.join(root, file), 'a+') as file1:
               file1.write('\n')
               file1.write('\n')
               file1.write(stra)  
            print 'Adding Junk to ' + file

for _ in range(500):
   add_junk()
   print _
