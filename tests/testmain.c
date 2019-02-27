/*
 * File:   testmain.c
 * Author: jcunha
 *
 * Created on 26/fev/2019
 */

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>

/*
 * CUnit Test Suite
 */

int init_suite(void) {
    return 0;
}

int clean_suite(void) {
    return 0;
}

/*
 *  Test add()
 */
int add(int p, int q);

void testAdd() {
    CU_ASSERT_EQUAL(add(0,0), 0);
    CU_ASSERT_EQUAL(add(1,0), 1);
    CU_ASSERT_EQUAL(add(-1,1), 0);
    CU_ASSERT_EQUAL(add(1000,999), 1999);
}


/*
 *  Test max()
 */
int max(int num1, int num2);

void testMax() {
     CU_ASSERT_EQUAL(max(0,0), 0);
     CU_ASSERT_EQUAL(max(1000,999), 1000);
     CU_ASSERT_EQUAL(max(999,1000), 1000);
     CU_ASSERT_EQUAL(max(10,-100), 10);
     CU_ASSERT_EQUAL(max(-50,-60), -50);
}


/*
 *  Test iseven()
 */
int iseven(int number);

void testIseven() {
//     CU_ASSERT_EQUAL(iseven(1), 1);
//     CU_ASSERT_EQUAL(iseven(2), 0);
//     CU_ASSERT_EQUAL(iseven(-10), 0);
}


int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("testmain", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "testAdd", testAdd)) ||
            (NULL == CU_add_test(pSuite, "testMax", testMax)) ||
            (NULL == CU_add_test(pSuite, "testMax", testIseven))
            ) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
