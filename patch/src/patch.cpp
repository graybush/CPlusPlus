#include <cstdio>
#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <time.h>
#include "PatchFactory.h"

// #include <iostream>
// #include <fcntl.h>
// #include <unistd.h>
// #include <cstdio>


int main(int argc, char* argv[], char* env[]) {

  // for (unsigned int i = 0; env[i] != NULL; ++i) {
  //   printf("%s\n", env[i]);
  // }

  PatchFactory* factory = new PatchFactory();
  std::vector<FileSet>* fileSet = factory->readAssembly(argv[1]);

  std::vector<FileSet>::iterator it;
  for (it = fileSet->begin(); it < fileSet->end(); ++it) {
    for (unsigned int jt = 0; jt < it->includes.size(); ++jt) {
      std::string path = it->directory + "/" + it->includes[jt];
      std::cout << path << std::endl;
    }
  }

  // std::ifstream src("./bin/patch", std::ios::binary);
  // std::ofstream dst("./patch", std::ios::binary);
  // dst << src.rdbuf();
  // src.close();
  // dst.close();
  // chmod("./patch", 0775);

  // struct stat t_stat;
  // stat("./patch", &t_stat);
  // std::cout << t_stat.st_mode << "\n";
  // struct tm* timeinfo = localtime(&t_stat.st_ctime);
  // printf("File time and date: %s", asctime(timeinfo));

  // size_t BUFSIZE = 4096;
  // char buf[BUFSIZE];
  // size_t size;
  // int src = open("/home/centos/downloads/offline-build.zip", O_RDONLY);
  // int dst = open("./here.zip", O_WRONLY | O_CREAT, 0644);
  // while ((size = read(src, buf, BUFSIZE)) > 0) {
  //   write(dst, buf, size);
  // }
  // close(src);
  // close(dst);

  delete fileSet;
  delete factory;

  return 0;
}
