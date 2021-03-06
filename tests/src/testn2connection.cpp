#include "stdio.h"
#include "CPPtester.h"
#include "n2draw.h"
#include "n2drawmanager.h"
#include "n2connection.h"
#include "n2exception.h"
#include "n2view.h"
#include <iostream>

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

class test_nnConnection
    : public caTester
{
    CA_TEST_SUITE(test_nnConnection)
    CA_TEST(test_nnConnection::test1, "verify vertical connection from component");
    CA_TEST(test_nnConnection::test2, "verify vertical connection from component");
    CA_TEST(test_nnConnection::test3, "verify vertical connection from component");
    CA_TEST(test_nnConnection::test4, "verify vertical connection from component");
    CA_TEST(test_nnConnection::test5, "verify vertical connection from component");
    CA_TEST(test_nnConnection::test6, "verify vertical connection from component");
    CA_TEST(test_nnConnection::test7, "verify horiz connection from component");
    CA_TEST(test_nnConnection::test8, "verify horiz connection from component");
    CA_TEST(test_nnConnection::test9, "verify horiz connection from component");
    CA_TEST(test_nnConnection::test10, "verify horiz connection from component");
    CA_TEST(test_nnConnection::test11, "verify horiz connection from component");
    CA_TEST_SUITE_END()
    void setUp(void) {}
    void tearDown(void) {}
    void test1(void);
    void test2(void);
    void test3(void);
    void test4(void);
    void test5(void);
    void test6(void);
    void test7(void);
    void test8(void);
    void test9(void);
    void test10(void);
    void test11(void);
};
///////////////////////////////////////////////////

REGISTER_CLASS(test_nnConnection);

void test_nnConnection::test1(void)
{
    _START();
    _INFO("verifica interrna alla classe: metodo connectComponent ");
    _AUTHOR("Coppi Angelo n2draw library ");
    _STOP();
    nnObjManager mn(50, 20);
    nnObjCoil * coil = new nnObjCoil();
    nnObjContact * contact = new nnObjContact();
    mn.addObj(5, 2, contact);
    mn.addObj(5, 10, coil);
    nnPoint p1(5, 2),p2(5, 10);
    bool res=nnConnection::connectComponent(&mn, p1,p2);
    CA_ASSERT(res == true);
    InnObj *w = mn.getObj(5, 3);
    CA_ASSERT(w!=nullptr);
    CA_ASSERT(w->isComponent()==false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireVertical);
    ////std::wcout << w->toString() << std::endl;
    w = mn.getObj(5, 4);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireVertical);
    ////std::wcout << w->toString() << std::endl;
    w = mn.getObj(5, 5);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireVertical);
    ////std::wcout << w->toString() << std::endl;
    w = mn.getObj(5, 6);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireVertical);
    ////std::wcout << w->toString() << std::endl;
    w = mn.getObj(5, 7);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireVertical);
    ////std::wcout << w->toString() << std::endl;
    w = mn.getObj(5, 8);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireVertical);
    ////std::wcout << w->toString() << std::endl;
    w = mn.getObj(5, 9);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireVertical);
    ////std::wcout << w->toString() << std::endl;
    CA_ASSERT(res == true);
    res = mn.removeAll();
    CA_ASSERT(res == true);
}


void test_nnConnection::test2(void)
{
    _START();
    _INFO("verifica interrna alla classe: metodo connectComponent ");
    _AUTHOR("Coppi Angelo n2draw library ");
    _STOP();
    nnObjManager mn(50, 20);
    nnObjCoil * coil = new nnObjCoil();
    nnObjContact * contact = new nnObjContact();
    mn.addObj(5, 2, contact);
    mn.addObj(5, 10, coil);
    nnPoint p1(5, 10),p2(5, 2);
    bool res = nnConnection::connectComponent(&mn,p1,p2);
    CA_ASSERT(res == true);
    InnObj *w = mn.getObj(5, 3);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireVertical);
    ////std::wcout << w->toString() << std::endl;
    w = mn.getObj(5, 4);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireVertical);
    ////std::wcout << w->toString() << std::endl;
    w = mn.getObj(5, 5);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireVertical);
    ////std::wcout << w->toString() << std::endl;
    w = mn.getObj(5, 6);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireVertical);
    ////std::wcout << w->toString() << std::endl;
    w = mn.getObj(5, 7);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireVertical);
    ////std::wcout << w->toString() << std::endl;
    w = mn.getObj(5, 8);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireVertical);
    ////std::wcout << w->toString() << std::endl;
    w = mn.getObj(5, 9);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireVertical);
    // //std::wcout << w->toString() << std::endl;
    CA_ASSERT(res == true);
    res = mn.removeAll();
    CA_ASSERT(res == true);
}

void test_nnConnection::test3(void)
{
    _START();
    _INFO("verifica interna alla classe: metodo connectComponent ");
    _INFO("verifica interna alla classe: componenti with connection ");
    _AUTHOR("Coppi Angelo n2draw library ");
    _STOP();
    nnObjManager mn(50, 20);
    nnObjCoil * coil = new nnObjCoil();
    nnObjContact * contact = new nnObjContact();
    mn.addObj(5, 2, contact);
    mn.addObj(5, 10, coil);
    nnObjWire *wire = new nnObjWire(eWire::wireAngleUpLeft);
    mn.addObj(5, 3, wire);
    nnPoint p1(5, 2),p2(5, 10);
    bool res = nnConnection::connectComponent(&mn, p1,p2);
    CA_ASSERT(res == true);
    InnObj *w = mn.getObj(5, 3);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireTVertLeft);
    ////std::wcout << w->toString() << std::endl;
    w = mn.getObj(5, 4);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireVertical);
    ////std::wcout << w->toString() << std::endl;
    w = mn.getObj(5, 5);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireVertical);
    ////std::wcout << w->toString() << std::endl;
    w = mn.getObj(5, 6);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireVertical);
    ////std::wcout << w->toString() << std::endl;
    w = mn.getObj(5, 7);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireVertical);
    ////std::wcout << w->toString() << std::endl;
    w = mn.getObj(5, 8);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireVertical);
    ////std::wcout << w->toString() << std::endl;
    w = mn.getObj(5, 9);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireVertical);
    ////std::wcout << w->toString() << std::endl;
    CA_ASSERT(res == true);
    res = mn.removeAll();
    CA_ASSERT(res == true);
}


void test_nnConnection::test4(void)
{
    _START();
    _INFO("verifica interna alla classe: metodo connectComponent ");
    _INFO("verifica interna alla classe: componenti with connection ");
    _AUTHOR("Coppi Angelo n2draw library ");
    _STOP();
    nnObjManager mn(50, 20);
    nnObjCoil * coil = new nnObjCoil();
    nnObjContact * contact = new nnObjContact();
    mn.addObj(5, 2, contact);
    mn.addObj(5, 10, coil);
    nnObjWire *wire = new nnObjWire(eWire::wireAngleUpRight);
    mn.addObj(5, 3, wire);
    nnPoint p1(5, 2),p2(5, 10);
    bool res = nnConnection::connectComponent(&mn, p1,p2);
    CA_ASSERT(res == true);
    InnObj *w = mn.getObj(5, 3);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireTVertRight);
    ////std::wcout << w->toString() << std::endl;
    w = mn.getObj(5, 4);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireVertical);
    ////std::wcout << w->toString() << std::endl;
    w = mn.getObj(5, 5);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireVertical);
    ////std::wcout << w->toString() << std::endl;
    w = mn.getObj(5, 6);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireVertical);
    ////std::wcout << w->toString() << std::endl;
    w = mn.getObj(5, 7);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireVertical);
    ////std::wcout << w->toString() << std::endl;
    w = mn.getObj(5, 8);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireVertical);
    ////std::wcout << w->toString() << std::endl;
    w = mn.getObj(5, 9);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireVertical);
    ////std::wcout << w->toString() << std::endl;
    CA_ASSERT(res == true);
    res = mn.removeAll();
    CA_ASSERT(res == true);
}


void test_nnConnection::test5(void)
{
    _START();
    _INFO("verifica interna alla classe: metodo connectComponent ");
    _INFO("verifica interna alla classe: componenti with connection ");
    _AUTHOR("Coppi Angelo n2draw library ");
    _STOP();
    nnObjManager mn(50, 20);
    nnObjCoil * coil = new nnObjCoil();
    nnObjContact * contact = new nnObjContact();
    mn.addObj(5, 2, contact);
    mn.addObj(5, 10, coil);
    nnObjWire *wire = new nnObjWire(eWire::wireTHorizUp);
    mn.addObj(5, 3, wire);
    nnPoint p1(5, 2),p2(5, 10);
    bool res = nnConnection::connectComponent(&mn, p1,p2);
    CA_ASSERT(res == true);
    InnObj *w = mn.getObj(5, 3);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireCross);
    ////std::wcout << w->toString() << std::endl;
    w = mn.getObj(5, 4);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireVertical);
    ////std::wcout << w->toString() << std::endl;
    w = mn.getObj(5, 5);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireVertical);
    ////std::wcout << w->toString() << std::endl;
    w = mn.getObj(5, 6);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireVertical);
    ////std::wcout << w->toString() << std::endl;
    w = mn.getObj(5, 7);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireVertical);
    ////std::wcout << w->toString() << std::endl;
    w = mn.getObj(5, 8);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireVertical);
    ////std::wcout << w->toString() << std::endl;
    w = mn.getObj(5, 9);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireVertical);
    ////std::wcout << w->toString() << std::endl;
    CA_ASSERT(res == true);
    res = mn.removeAll();
    CA_ASSERT(res == true);
}

void test_nnConnection::test6(void)
{
    _START();
    _INFO("verifica interna alla classe: metodo connectComponent ");
    _INFO("verifica interna alla classe: componenti with connection ");
    _AUTHOR("Coppi Angelo n2draw library ");
    _STOP();
    bool res;
    nnObjManager mn(50, 20);
    nnObjCoil * coil = new nnObjCoil();
    nnObjContact * contact = new nnObjContact();
    mn.addObj(5, 2, contact);
    mn.addObj(5, 10, coil);
    nnObjWire *wire = new nnObjWire(eWire::wireAngleDownLeft);
    mn.addObj(5, 9, wire);
    nnPoint p1(5, 2),p2(5, 10);
    try
    {

        res = nnConnection::connectComponent(&mn, p1,p2);
        CA_ASSERT(res == false);
    }
    catch (positionBusyException *e)
    {
        CA_ASSERT(e==nullptr);
        delete e;

    }
    catch (wireConnectionException *v)
    {
        CA_ASSERT(v->down[0] == 4);
        delete v;
    }
    InnObj *w = mn.getObj(5, 3);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireVertical);
    //std::wcout << w->toString() << std::endl;
    w = mn.getObj(5, 4);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireVertical);
    //std::wcout << w->toString() << std::endl;
    w = mn.getObj(5, 5);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireVertical);
    //std::wcout << w->toString() << std::endl;
    w = mn.getObj(5, 6);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireVertical);
    //std::wcout << w->toString() << std::endl;
    w = mn.getObj(5, 7);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireVertical);
    //std::wcout << w->toString() << std::endl;
    w = mn.getObj(5, 8);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::noWire);
    //std::wcout << w->toString() << std::endl;
    w = mn.getObj(5, 9);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireAngleDownLeft);
    //std::wcout << w->toString() << std::endl;
    res = mn.removeAll();
    CA_ASSERT(res == true);
}



void test_nnConnection::test7(void)
{
    _START();
    _INFO("verifica interna alla classe: metodo connectComponent ");
    _INFO("verifica interna alla classe: component with connection ");
    _AUTHOR("Coppi Angelo n2draw library ");
    _STOP();
    nnObjManager mn(50, 20);
    nnObjCoil * coil = new nnObjCoil();
    nnObjContact * contact = new nnObjContact();
    mn.addObj(5, 5, contact);
    mn.addObj(11, 5, coil);
    nnPoint p1(5, 5);
    nnPoint p2(11, 5);
    bool res = nnConnection::connectComponent(&mn, p1, p2);
    CA_ASSERT(res == true);
    InnObj *w = mn.getObj(5, 4);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireAngleDownRight);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front()==3);
    //std::wcout << w->toString() << std::endl;
    w = mn.getObj(6, 4);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireHorizzontal);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 3);

    //std::wcout << w->toString() << std::endl;
    w = mn.getObj(7, 4);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireHorizzontal);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 3);

    //std::wcout << w->toString() << std::endl;
    w = mn.getObj(8, 4);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireHorizzontal);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 3);

    //std::wcout << w->toString() << std::endl;
    w = mn.getObj(9, 4);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireHorizzontal);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 3);

    //std::wcout << w->toString() << std::endl;
    w = mn.getObj(10, 4);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireHorizzontal);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 3);

    //std::wcout << w->toString() << std::endl;
    w = mn.getObj(11, 4);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireAngleDownLeft);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 3);

    //std::wcout << w->toString() << std::endl;

    w = mn.getObj(5, 6);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireAngleUpRight);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 4);

    //std::wcout << w->toString() << std::endl;
    w = mn.getObj(6, 6);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireHorizzontal);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 4);

    //std::wcout << w->toString() << std::endl;
    w = mn.getObj(7, 6);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireHorizzontal);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 4);

    //std::wcout << w->toString() << std::endl;
    w = mn.getObj(8,6);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireHorizzontal);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 4);

    //std::wcout << w->toString() << std::endl;
    w = mn.getObj(9, 6);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireHorizzontal);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 4);

    //std::wcout << w->toString() << std::endl;
    w = mn.getObj(10, 6);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireHorizzontal);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 4);

    //std::wcout << w->toString() << std::endl;
    w = mn.getObj(11, 6);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireAngleUpLeft);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 4);

    //std::wcout << w->toString() << std::endl;
    res = mn.removeAll();
    CA_ASSERT(res == true);
}


void test_nnConnection::test8(void)
{
    _START();
    _INFO("method connectComponent ");
    _INFO("component with connection ");
    _INFO("connection with component already connected ");
    _AUTHOR("Coppi Angelo n2draw library ");
    _STOP();
    nnObjManager mn(50, 20);
    nnObjCoil * coil = new nnObjCoil();
    nnObjContact * contact = new nnObjContact();
    mn.addObj(5, 5, contact);
    mn.addObj(11, 5, coil);
    nnPoint p1(5, 5);
    nnPoint p2(11, 5);
    bool res = nnConnection::connectComponent(&mn, p1, p2);
    CA_ASSERT(res==true);
    InnObj *w = mn.getObj(5, 4);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireAngleDownRight);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 3);
    CA_ASSERT(w->getConnections().size() == 1);
    //std::wcout << w->toString() << std::endl;
    w = mn.getObj(6, 4);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireHorizzontal);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 3);
    CA_ASSERT(w->getConnections().size() == 1);

    //std::wcout << w->toString() << std::endl;
    w = mn.getObj(7, 4);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireHorizzontal);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 3);
    CA_ASSERT(w->getConnections().size() == 1);

    //std::wcout << w->toString() << std::endl;
    w = mn.getObj(8, 4);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireHorizzontal);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 3);
    CA_ASSERT(w->getConnections().size() == 1);

    //std::wcout << w->toString() << std::endl;
    w = mn.getObj(9, 4);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireHorizzontal);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 3);
    CA_ASSERT(w->getConnections().size() == 1);

    //std::wcout << w->toString() << std::endl;
    w = mn.getObj(10, 4);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireHorizzontal);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 3);
    CA_ASSERT(w->getConnections().size() == 1);

    //std::wcout << w->toString() << std::endl;
    w = mn.getObj(11, 4);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireAngleDownLeft);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 3);
    CA_ASSERT(w->getConnections().size() == 1);

    //std::wcout << w->toString() << std::endl;

    w = mn.getObj(5, 6);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireAngleUpRight);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 4);
    CA_ASSERT(w->getConnections().size() == 1);

    //std::wcout << w->toString() << std::endl;
    w = mn.getObj(6, 6);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireHorizzontal);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 4);
    CA_ASSERT(w->getConnections().size() == 1);

    //std::wcout << w->toString() << std::endl;
    w = mn.getObj(7, 6);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireHorizzontal);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 4);
    CA_ASSERT(w->getConnections().size() == 1);

    //std::wcout << w->toString() << std::endl;
    w = mn.getObj(8, 6);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireHorizzontal);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 4);
    CA_ASSERT(w->getConnections().size() == 1);

    //std::wcout << w->toString() << std::endl;
    w = mn.getObj(9, 6);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireHorizzontal);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 4);
    CA_ASSERT(w->getConnections().size() == 1);

    //std::wcout << w->toString() << std::endl;
    w = mn.getObj(10, 6);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireHorizzontal);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 4);
    CA_ASSERT(w->getConnections().size() == 1);

    //std::wcout << w->toString() << std::endl;
    w = mn.getObj(11, 6);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireAngleUpLeft);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 4);
    CA_ASSERT(w->getConnections().size() == 1);

    //std::wcout << w->toString() << std::endl;

    // ADD ANOTHER COMPO

    nnObjContact * contact1 = new nnObjContact();
    mn.addObj(15, 5, contact1);
    nnPoint p3(15, 5);
    res = nnConnection::connectComponent(&mn, p2, p3);
    CA_ASSERT(res == true);

    w = mn.getObj(11, 4);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireTHorizDown);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 3);
    CA_ASSERT(w->getConnections().size() == 1);
    //std::wcout << w->toString() << std::endl;

    w = mn.getObj(12, 4);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireHorizzontal);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 3);
    CA_ASSERT(w->getConnections().size() == 1);
    //std::wcout << w->toString() << std::endl;

    w = mn.getObj(13, 4);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireHorizzontal);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 3);
    CA_ASSERT(w->getConnections().size() == 1);
    //std::wcout << w->toString() << std::endl;

    w = mn.getObj(14, 4);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireHorizzontal);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 3);
    CA_ASSERT(w->getConnections().size() == 1);
    //std::wcout << w->toString() << std::endl;

    w = mn.getObj(15, 4);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireAngleDownLeft);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 3);
    CA_ASSERT(w->getConnections().size() == 1);
    //std::wcout << w->toString() << std::endl;

    w = mn.getObj(11, 6);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireTHorizUp);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 4);
    CA_ASSERT(w->getConnections().size() == 1);
    //std::wcout << w->toString() << std::endl;

    w = mn.getObj(12, 6);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireHorizzontal);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 4);
    CA_ASSERT(w->getConnections().size() == 1);
    //std::wcout << w->toString() << std::endl;

    w = mn.getObj(13, 6);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireHorizzontal);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 4);
    CA_ASSERT(w->getConnections().size() == 1);
    //std::wcout << w->toString() << std::endl;

    w = mn.getObj(14, 6);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireHorizzontal);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 4);
    CA_ASSERT(w->getConnections().size() == 1);
    //std::wcout << w->toString() << std::endl;

    w = mn.getObj(15, 6);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireAngleUpLeft);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 4);
    CA_ASSERT(w->getConnections().size() == 1);
    //std::wcout << w->toString() << std::endl;



    res = mn.removeAll();
    CA_ASSERT(res == true);
}


void test_nnConnection::test9(void)
{
    _START();
    _INFO("verifica interna alla classe: metodo connectComponent ");
    _INFO("verifica interna alla classe: component with connection ");
    _AUTHOR("Coppi Angelo n2draw library ");
    _STOP();
    nnObjManager mn(50, 20);
    nnObjCoil * coil = new nnObjCoil();
    nnObjContact * contact = new nnObjContact();
    mn.addObj(5, 5, contact);
    mn.addObj(11, 5, coil);
    nnPoint p1(5, 5);
    nnPoint p2(11, 5);
    bool res = nnConnection::connectComponent(&mn, p2, p1);
    CA_ASSERT(res == true);
    InnObj *w = mn.getObj(5, 4);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireAngleDownRight);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 3);
    //std::wcout << w->toString() << std::endl;
    w = mn.getObj(6, 4);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireHorizzontal);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 3);

    //std::wcout << w->toString() << std::endl;
    w = mn.getObj(7, 4);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireHorizzontal);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 3);

    //std::wcout << w->toString() << std::endl;
    w = mn.getObj(8, 4);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireHorizzontal);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 3);

    //std::wcout << w->toString() << std::endl;
    w = mn.getObj(9, 4);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireHorizzontal);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 3);

    //std::wcout << w->toString() << std::endl;
    w = mn.getObj(10, 4);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireHorizzontal);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 3);

    //std::wcout << w->toString() << std::endl;
    w = mn.getObj(11, 4);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireAngleDownLeft);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 3);

    //std::wcout << w->toString() << std::endl;

    w = mn.getObj(5, 6);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireAngleUpRight);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 4);

    //std::wcout << w->toString() << std::endl;
    w = mn.getObj(6, 6);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireHorizzontal);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 4);

    //std::wcout << w->toString() << std::endl;
    w = mn.getObj(7, 6);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireHorizzontal);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 4);

    //std::wcout << w->toString() << std::endl;
    w = mn.getObj(8, 6);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireHorizzontal);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 4);

    //std::wcout << w->toString() << std::endl;
    w = mn.getObj(9, 6);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireHorizzontal);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 4);

    //std::wcout << w->toString() << std::endl;
    w = mn.getObj(10, 6);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireHorizzontal);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 4);

    //std::wcout << w->toString() << std::endl;
    w = mn.getObj(11, 6);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireAngleUpLeft);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 4);

    //std::wcout << w->toString() << std::endl;
    res = mn.removeAll();
    CA_ASSERT(res == true);
}


void test_nnConnection::test10(void)
{
    _START();
    _INFO("method connectComponent ");
    _INFO("component with connection ");
    _INFO("connection with component already connected ");
    _AUTHOR("Coppi Angelo n2draw library ");
    _STOP();
    nnObjManager mn(50, 20);
    nnObjCoil * coil = new nnObjCoil();
    nnObjContact * contact = new nnObjContact();
    mn.addObj(5, 5, contact);
    mn.addObj(11, 5, coil);
    nnPoint p1(5, 5);
    nnPoint p2(11, 5);
    bool res = nnConnection::connectComponent(&mn, p2, p1);
    CA_ASSERT(res == true);
    InnObj *w = mn.getObj(5, 4);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireAngleDownRight);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 3);
    CA_ASSERT(w->getConnections().size() == 1);
    //std::wcout << w->toString() << std::endl;
    w = mn.getObj(6, 4);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireHorizzontal);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 3);
    CA_ASSERT(w->getConnections().size() == 1);

    //std::wcout << w->toString() << std::endl;
    w = mn.getObj(7, 4);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireHorizzontal);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 3);
    CA_ASSERT(w->getConnections().size() == 1);

    //std::wcout << w->toString() << std::endl;
    w = mn.getObj(8, 4);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireHorizzontal);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 3);
    CA_ASSERT(w->getConnections().size() == 1);

    //std::wcout << w->toString() << std::endl;
    w = mn.getObj(9, 4);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireHorizzontal);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 3);
    CA_ASSERT(w->getConnections().size() == 1);

    //std::wcout << w->toString() << std::endl;
    w = mn.getObj(10, 4);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireHorizzontal);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 3);
    CA_ASSERT(w->getConnections().size() == 1);

    //std::wcout << w->toString() << std::endl;
    w = mn.getObj(11, 4);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireAngleDownLeft);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 3);
    CA_ASSERT(w->getConnections().size() == 1);

    //std::wcout << w->toString() << std::endl;

    w = mn.getObj(5, 6);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireAngleUpRight);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 4);
    CA_ASSERT(w->getConnections().size() == 1);

    //std::wcout << w->toString() << std::endl;
    w = mn.getObj(6, 6);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireHorizzontal);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 4);
    CA_ASSERT(w->getConnections().size() == 1);

    //std::wcout << w->toString() << std::endl;
    w = mn.getObj(7, 6);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireHorizzontal);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 4);
    CA_ASSERT(w->getConnections().size() == 1);

    //std::wcout << w->toString() << std::endl;
    w = mn.getObj(8, 6);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireHorizzontal);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 4);
    CA_ASSERT(w->getConnections().size() == 1);

    //std::wcout << w->toString() << std::endl;
    w = mn.getObj(9, 6);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireHorizzontal);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 4);
    CA_ASSERT(w->getConnections().size() == 1);

    //std::wcout << w->toString() << std::endl;
    w = mn.getObj(10, 6);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireHorizzontal);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 4);
    CA_ASSERT(w->getConnections().size() == 1);

    //std::wcout << w->toString() << std::endl;
    w = mn.getObj(11, 6);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireAngleUpLeft);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 4);
    CA_ASSERT(w->getConnections().size() == 1);

    //std::wcout << w->toString() << std::endl;

    // ADD ANOTHER COMPO

    nnObjContact * contact1 = new nnObjContact();
    mn.addObj(1, 5, contact1);
    nnPoint p3(1, 5);
    res = nnConnection::connectComponent(&mn, p1, p3);
    CA_ASSERT(res == true);

    w = mn.getObj(5, 4);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireTHorizDown);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 3);
    CA_ASSERT(w->getConnections().size() == 1);
    //std::wcout << w->toString() << std::endl;

    w = mn.getObj(4, 4);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireHorizzontal);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 3);
    CA_ASSERT(w->getConnections().size() == 1);
    //std::wcout << w->toString() << std::endl;

    w = mn.getObj(3, 4);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireHorizzontal);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 3);
    CA_ASSERT(w->getConnections().size() == 1);
    //std::wcout << w->toString() << std::endl;

    w = mn.getObj(2, 4);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireHorizzontal);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 3);
    CA_ASSERT(w->getConnections().size() == 1);
    //std::wcout << w->toString() << std::endl;

    w = mn.getObj(1, 4);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireAngleDownRight);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 3);
    CA_ASSERT(w->getConnections().size() == 1);
    //std::wcout << w->toString() << std::endl;

    w = mn.getObj(5, 6);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireTHorizUp);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 4);
    CA_ASSERT(w->getConnections().size() == 1);
    //std::wcout << w->toString() << std::endl;

    w = mn.getObj(4, 6);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireHorizzontal);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 4);
    CA_ASSERT(w->getConnections().size() == 1);
    //std::wcout << w->toString() << std::endl;

    w = mn.getObj(3, 6);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireHorizzontal);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 4);
    CA_ASSERT(w->getConnections().size() == 1);
    //std::wcout << w->toString() << std::endl;

    w = mn.getObj(2, 6);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireHorizzontal);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 4);
    CA_ASSERT(w->getConnections().size() == 1);
    //std::wcout << w->toString() << std::endl;


    w = mn.getObj(1, 6);
    CA_ASSERT(w != nullptr);
    CA_ASSERT(w->isComponent() == false);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getWire() == eWire::wireAngleUpRight);
    CA_ASSERT(dynamic_cast<nnObjWire*>(w)->getConnections().front() == 4);
    CA_ASSERT(w->getConnections().size() == 1);
    //std::wcout << w->toString() << std::endl;



    res = mn.removeAll();
    CA_ASSERT(res == true);
}


void test_nnConnection::test11(void)
{
    _START();
    _INFO("method connectComponent ");
    _INFO("component with connection ");
    _INFO("connect 1 wire to component");
    _AUTHOR("Coppi Angelo n2draw library ");
    _STOP();
    nnObjManager mn(50, 20);
    nnObjCoil * coil = new nnObjCoil();
    nnObjContact * contact = new nnObjContact();
    nnObjWire *wire = new nnObjWire(eWire::noWire);
    mn.addObj(5, 0, wire);
    mn.addObj(5, 5, contact);
    mn.addObj(5, 19,coil);
    nnPoint p0(5, 0);
    nnPoint p1(5, 5);
    nnPoint p2(5, 19);
    bool res = nnConnection::connectComponent(&mn, p0, p1);
    CA_ASSERT(res==true);
    res = nnConnection::connectComponent(&mn, p1, p2);
    CA_ASSERT(res == true);
    coil = new nnObjCoil();
    contact = new nnObjContact();
    wire = new nnObjWire(eWire::noWire);
    mn.addObj(15, 0, wire);
    mn.addObj(15, 5, contact);
    mn.addObj(15, 19, coil);
    nnPoint p3(15, 0);
    nnPoint p4(15, 5);
    nnPoint p5(15, 19);
    res = nnConnection::connectComponent(&mn, p3, p4);
    CA_ASSERT(res == true);
    res = nnConnection::connectComponent(&mn, p4, p5);
    CA_ASSERT(res == true);
}
