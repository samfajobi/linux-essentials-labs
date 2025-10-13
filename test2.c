static int DetectWindowTestParse01 (void)
{
    DetectWindowData *wd = NULL;
    wd = DetectWindowParse(NULL, "35402");
    FAIL_IF_NULL(wd);
    FAIL_IF_NOT(wd->size == 35402);

    DetectWindowFree(NULL, wd);
    PASS;
}

/**
 * \test DetectWindowTestParse02 is a test for setting the window opt negated
 */
static int DetectWindowTestParse02 (void)
{
    DetectWindowData *wd = NULL;
    wd = DetectWindowParse(NULL, "!35402");
    FAIL_IF_NULL(wd);
    FAIL_IF_NOT(wd->negated == 1);
    FAIL_IF_NOT(wd->size == 35402);

    DetectWindowFree(NULL, wd);
    PASS;
}

/**
 * \test DetectWindowTestParse03 is a test to check for an empty value
 */
static int DetectWindowTestParse03 (void)
{
    DetectWindowData *wd = NULL;
    wd = DetectWindowParse(NULL, "");
    FAIL_IF_NOT_NULL(wd);

    DetectWindowFree(NULL, wd);
    PASS;
}

/**
 * \test DetectWindowTestParse03 is a test to check for a big value
 */
static int DetectWindowTestParse04 (void)
{
    DetectWindowData *wd = NULL;
    wd = DetectWindowParse(NULL, "1235402");
    FAIL_IF_NOT_NULL(wd);

    DetectWindowFree(NULL, wd);
    PASS;
}
