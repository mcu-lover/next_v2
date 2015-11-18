#include <stdio.h>
#include <string>
#include "CPPtester.h"
#include "miniXml.h"


/**************************************************************
Copyright(c) 2015 Angelo Coppi

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files(the "Software"), to deal in the Software without
restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and / or sell
copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following
conditions :

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT.IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.
********************************************************************/

///////////////////// HEADER //////////////////////

class test_miniXml_class
    : public caTester
{
    CA_TEST_SUITE(test_miniXml_class)
    CA_TEST(test_miniXml_class::test1, "xlnode");
    CA_TEST(test_miniXml_class::test2, "xlnode");
    CA_TEST(test_miniXml_class::test3, "xlnode");
    CA_TEST(test_miniXml_class::test4, "xlnode");
    CA_TEST(test_miniXml_class::test5, "xlnode");
    CA_TEST(test_miniXml_class::test6, "xlnode");
    CA_TEST_SUITE_END()
    void setUp(void);
    void tearDown(void);
    void test1(void);
    void test2(void);
    void test3(void);
    void test4(void);
    void test5(void);
    void test6(void);
};
///////////////////////////////////////////////////

REGISTER_CLASS(test_miniXml_class);

void test_miniXml_class::setUp(void)
{

}

void test_miniXml_class::tearDown(void)
{

}

void test_miniXml_class::test1(void)
{
    _START();
    _INFO("create XmlNode");
    _AUTHOR("Coppi Angelo n2draw library ");
    _STOP();

    miniXmlNode root("ROOT", (char*)"");
    miniXmlNode* child1=root.add("child1", (char*)"1000");
    miniXmlNode* child2=child1->add("child2", (char*)"2000");
    root.print(stdout);
    CA_ASSERT(root.getParent() == nullptr);
    CA_ASSERT(root.getChild() == child1);
    CA_ASSERT(root.getNext() == nullptr);
    CA_ASSERT(child1->getChild() == child2);
}

void test_miniXml_class::test2(void)
{
    _START();
    _INFO("create XmlNode");
    _AUTHOR("Coppi Angelo n2draw library ");
    _STOP();

    miniXmlNode root("ROOT", (char*)"");
    miniXmlNode* child1 = root.add("child1",(char*) "1000");
    miniXmlNode* child2 = root.add("child2", (char*)"2000");
    root.print(stdout);
    CA_ASSERT(root.getParent() == nullptr);
    CA_ASSERT(root.getChild() == child1);
    CA_ASSERT(root.getNext() == nullptr);
    CA_ASSERT(child1->getNext() == child2);
}



void test_miniXml_class::test3(void)
{
    _START();
    _INFO("parse XmlNode");
    _AUTHOR("Coppi Angelo n2draw library ");
    _STOP();
        remove(".\\test3.xml");
        const char *xml="<ROOT>\r\n<child1>\r\n1000\r\n</child1>\r\n<child2>\r\n2000\r\n</child2>\r\n</ROOT>\r\n";
        FILE *f=fopen(".\\test3.xml","w+");
        fwrite(xml,1,strlen(xml),f);
        fclose(f);
    miniXmlNode root("",(char *)"");
    root.load(".\\test3.xml",&root);
    root.print(stdout);
    remove(".\\test3.xml");
    CA_ASSERT(root.find("child1") != NULL);
    CA_ASSERT(root.find("child2") != NULL);
}

void test_miniXml_class::test4(void)
{
    _START();
    _INFO("create XmlNode and parse");
    _AUTHOR("Coppi Angelo n2draw library ");
    _STOP();

    miniXmlNode root("ROOT", (char*)"");
    miniXmlNode* child1 = root.add("child1", (char*)"1000");
    miniXmlNode* child2 = root.add("child2", (char*)"2000");
    miniXmlNode* child3 = root.add("child3", (char*)"3000");
    miniXmlNode* child4 = root.add("child4", (char*)"4000");
    miniXmlNode* child5 = root.add("child5", (char*)"5000");
    CA_ASSERT(root.getParent() == nullptr);
    CA_ASSERT(root.getChild() == child1);
    CA_ASSERT(root.getNext() == nullptr);
    CA_ASSERT(child1->getNext() == child2);
    root.print(stdout);
    remove(".\\test4.xml");
    FILE *f = fopen(".\\test4.xml", "w+");
    root.print(f);
    fclose(f);
    miniXmlNode root1("", (char*)"");
    root1.load(".\\test4.xml", &root1);
    root1.print(stdout);
    remove(".\\test4.xml");
    CA_ASSERT(root1.find("child1") != NULL);
    CA_ASSERT(root1.find("child2") != NULL);
    CA_ASSERT(root1.find("child3") != NULL);
    CA_ASSERT(root1.find("child4") != NULL);
    CA_ASSERT(root1.find("child5") != NULL);
}

void test_miniXml_class::test5(void)
{
    _START();
    _INFO("create XmlNode and parse");
    _AUTHOR("Coppi Angelo n2draw library ");
    _STOP();
    miniXmlNode root("ROOT", (char*)"");
    miniXmlNode* child1 = root.add("child1", (char*)"1000");
    miniXmlNode* child2 = root.add("child1.child2", (char*)"2000");
    miniXmlNode* child3 = root.add("child1.child2.child3", (char*)"3000");
    miniXmlNode* child4 = root.add("child1.child2.child3.child4", (char*)"4000");
    miniXmlNode* child5 = root.add("child1.child2.child3.child4.child5", (char*)"5000");
    CA_ASSERT(root.getParent() == nullptr);
    CA_ASSERT(root.getChild() == child1);
    CA_ASSERT(root.getNext() == nullptr);
    CA_ASSERT(child1->getNext() == nullptr);
    CA_ASSERT(child1->getChild() == child2);
    root.print(stdout);
    remove(".\\test5.xml");
    FILE *f = fopen(".\\test5.xml", "w+");
    root.print(f);
    fclose(f);
    miniXmlNode root1("", (char*)"");
    root1.load(".\\test5.xml", &root1);
    root1.print(stdout);
    remove(".\\test5.xml");
    CA_ASSERT(root1.find("child1") != NULL);
    CA_ASSERT(root1.find("child1.child2") != NULL);
    CA_ASSERT(root1.find("child1.child2.child3") != NULL);
    CA_ASSERT(root1.find("child1.child2.child3.child4") != NULL);
    CA_ASSERT(root1.find("child1.child2.child3.child4.child5") != NULL);
}


void test_miniXml_class::test6(void)
{
    _START();
    _INFO("create XmlNode and parse");
    _AUTHOR("Coppi Angelo n2draw library ");
    _STOP();

    miniXmlNode root("ROOT", (char*)"1000");
    miniXmlNode* child1 = root.add("child1", (char*)"1000");
    miniXmlNode* child2 = root.add("child2", (char*)"2000");
    CA_ASSERT(root.getParent() == nullptr);
    CA_ASSERT(root.getChild() == child1);
    CA_ASSERT(root.getNext() == nullptr);
    CA_ASSERT(child1->getNext() == child2);
    root.print(stdout);
    remove(".\\test6.xml");
    FILE *f = fopen(".\\test6.xml", "w+");
    root.print(f);
    fclose(f);
    miniXmlNode root1("", (char*)"");
    root1.load(".\\test6.xml", &root1);
    root1.print(stdout);
    remove(".\\test6.xml");
    CA_ASSERT(strcmp(root1.getValue(),"1000") ==0);
    CA_ASSERT(root1.find("child1") != NULL);
    CA_ASSERT(root1.find("child2") != NULL);
}