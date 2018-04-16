#include "PatchFactory.h"

PatchFactory::PatchFactory() {

  xmlInitParser();
  return;

}

PatchFactory::~PatchFactory() {

  xmlCleanupParser();
  return;

}

std::vector<std::string> PatchFactory::readIncludes(
    xmlDocPtr doc, xmlNodePtr cur) {

  std::vector<std::string> ret;
  xmlChar* key;
  cur = cur->xmlChildrenNode;
  while (cur != NULL) {
    if ((!xmlStrcmp(cur->name, (const xmlChar*)"include"))) {
      key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
      std::string str(reinterpret_cast<char*>(key));
      ret.push_back(str);
      // printf("include: %s\n", key);
      xmlFree(key);
    }
    cur = cur->next;
  }

  return ret;
}

FileSet PatchFactory::readFileSet(xmlDocPtr doc, xmlNodePtr cur) {

  FileSet ret;
  xmlChar* key;
  cur = cur->xmlChildrenNode;
  while (cur != NULL) {
    if ((!xmlStrcmp(cur->name, (const xmlChar*)"directory"))) {
      key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
      std::string str(reinterpret_cast<char*>(key));
      ret.directory = str;
      // printf("directory: %s\n", key);
      xmlFree(key);
    } else if ((!xmlStrcmp(cur->name, (const xmlChar*)"includes"))) {
      ret.includes = readIncludes(doc, cur);
    }
    cur = cur->next;
  }

  return ret;
}

std::vector<FileSet>* PatchFactory::readFileSets(
    xmlDocPtr doc, xmlNodePtr cur) {

  std::vector<FileSet>* ret = new std::vector<FileSet>;
  xmlChar* key;
  cur = cur->xmlChildrenNode;
  while (cur != NULL) {
    if ((!xmlStrcmp(cur->name, (const xmlChar*)"fileSet"))) {
      // key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
      // printf("fileSet: %s\n", key);
      ret->push_back(readFileSet(doc, cur));
      // xmlFree(key);
    }
    cur = cur->next;
  }

  return ret;
}

std::vector<FileSet>* PatchFactory::readAssembly(const char* assembly) {

  std::vector<FileSet>* ret = new std::vector<FileSet>;
  xmlDocPtr doc;
  doc = xmlParseFile(assembly);
  try {
    if (doc != NULL) {
      xmlNodePtr cur;
      cur = xmlDocGetRootElement(doc);
      if (cur != NULL) {
        if (!(xmlStrcmp(cur->name, (const xmlChar*) "assembly"))) {
          cur = cur->xmlChildrenNode;
          while (cur != NULL) {
            // std::cout << cur->name << std::endl;
            if ((!xmlStrcmp(cur->name, (const xmlChar*)"fileSets"))) {
              ret = readFileSets(doc, cur);
            }
            cur = cur->next;
          }
        } else {
          throw "not assembly.xml file";
        }
      } else {
        throw "empty document";
      }
    } else {
      throw "parsing assembly file";
    }
  } catch (const char* msg) {
    fprintf(stderr, "Error: %s.\n", msg);
  }
  xmlFreeDoc(doc);
  return ret;
}
