#ifndef PATCHFACTORY_H
#define PATCHFACTORY_H

#include <iostream>
#include <vector>
#include <libxml/encoding.h>
#include <libxml/parser.h> 
#include <libxml/valid.h>  
#include <libxml/xmlschemas.h>
#include <libxml/xmlreader.h>
#include <libxml/xmlwriter.h>

struct FileSet {
  
  std::string directory;
  std::vector<std::string> includes;

};

class PatchFactory {

  public:
    PatchFactory();
    ~PatchFactory();
    std::vector<FileSet>* readAssembly(const char* file);

  private:
    std::vector<FileSet>* readFileSets(xmlDocPtr doc, xmlNodePtr cur);
    FileSet readFileSet(xmlDocPtr doc, xmlNodePtr cur);
    std::vector<std::string> readIncludes(xmlDocPtr doc, xmlNodePtr cur);

};

#endif
