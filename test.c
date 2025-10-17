/** \test   Test the Urilen keyword setup */
static int DetectUrilenParseTest01(void)
{
    int ret = 0;
    DetectUrilenData *urilend = NULL;

    urilend = DetectUrilenParse("10");
    if (urilend != NULL) {
        if (urilend->du16.arg1 == 10 && urilend->du16.mode == DETECT_UINT_EQ &&
                !urilend->raw_buffer)
            ret = 1;

        DetectUrilenFree(NULL, urilend);
    }
    return ret;
}

/** \test   Test the Urilen keyword setup */
static int DetectUrilenParseTest02(void)
{
    int ret = 0;
    DetectUrilenData *urilend = NULL;

    urilend = DetectUrilenParse(" < 10  ");
    if (urilend != NULL) {
        if (urilend->du16.arg1 == 10 && urilend->du16.mode == DETECT_UINT_LT &&
                !urilend->raw_buffer)
            ret = 1;

        DetectUrilenFree(NULL, urilend);
    }
    return ret;
}

/** \test   Test the Urilen keyword setup */
static int DetectUrilenParseTest03(void)
{
    int ret = 0;
    DetectUrilenData *urilend = NULL;

    urilend = DetectUrilenParse(" > 10 ");
    if (urilend != NULL) {
        if (urilend->du16.arg1 == 10 && urilend->du16.mode == DETECT_UINT_GT &&
                !urilend->raw_buffer)
            ret = 1;

        DetectUrilenFree(NULL, urilend);
    }
    return ret;
}

/** \test   Test the Urilen keyword setup */
static int DetectUrilenParseTest04(void)
{
    int ret = 0;
    DetectUrilenData *urilend = NULL;

    urilend = DetectUrilenParse(" 5 <> 10 ");
    if (urilend != NULL) {
        if (urilend->du16.arg1 == 5 && urilend->du16.arg2 == 10 &&
                urilend->du16.mode == DETECT_UINT_RA && !urilend->raw_buffer)
            ret = 1;

        DetectUrilenFree(NULL, urilend);
    }
    return ret;
}

/** \test   Test the Urilen keyword setup */
static int DetectUrilenParseTest05(void)
{
    int ret = 0;
    DetectUrilenData *urilend = NULL;

    urilend = DetectUrilenParse("5<>10,norm");
    if (urilend != NULL) {
        if (urilend->du16.arg1 == 5 && urilend->du16.arg2 == 10 &&
                urilend->du16.mode == DETECT_UINT_RA && !urilend->raw_buffer)
            ret = 1;

        DetectUrilenFree(NULL, urilend);
    }
    return ret;
}

/** \test   Test the Urilen keyword setup */
static int DetectUrilenParseTest06(void)
{
    int ret = 0;
    DetectUrilenData *urilend = NULL;

    urilend = DetectUrilenParse("5<>10,raw");
    if (urilend != NULL) {
        if (urilend->du16.arg1 == 5 && urilend->du16.arg2 == 10 &&
                urilend->du16.mode == DETECT_UINT_RA && urilend->raw_buffer)
            ret = 1;

        DetectUrilenFree(NULL, urilend);
    }
    return ret;
}

/** \test   Test the Urilen keyword setup */
static int DetectUrilenParseTest07(void)
{
    int ret = 0;
    DetectUrilenData *urilend = NULL;

    urilend = DetectUrilenParse(">10, norm ");
    if (urilend != NULL) {
        if (urilend->du16.arg1 == 10 && urilend->du16.mode == DETECT_UINT_GT &&
                !urilend->raw_buffer)
            ret = 1;

        DetectUrilenFree(NULL, urilend);
    }
    return ret;
}

/** \test   Test the Urilen keyword setup */
static int DetectUrilenParseTest08(void)
{
    int ret = 0;
    DetectUrilenData *urilend = NULL;

    urilend = DetectUrilenParse("<10, norm ");
    if (urilend != NULL) {
        if (urilend->du16.arg1 == 10 && urilend->du16.mode == DETECT_UINT_LT &&
                !urilend->raw_buffer)
            ret = 1;

        DetectUrilenFree(NULL, urilend);
    }
    return ret;
}

/** \test   Test the Urilen keyword setup */
static int DetectUrilenParseTest09(void)
{
    int ret = 0;
    DetectUrilenData *urilend = NULL;

    urilend = DetectUrilenParse(">10, raw ");
    if (urilend != NULL) {
        if (urilend->du16.arg1 == 10 && urilend->du16.mode == DETECT_UINT_GT && urilend->raw_buffer)
            ret = 1;

        DetectUrilenFree(NULL, urilend);
    }
    return ret;
}

/** \test   Test the Urilen keyword setup */
static int DetectUrilenParseTest10(void)
{
    int ret = 0;
    DetectUrilenData *urilend = NULL;

    urilend = DetectUrilenParse("<10, raw ");
    if (urilend != NULL) {
        if (urilend->du16.arg1 == 10 && urilend->du16.mode == DETECT_UINT_LT && urilend->raw_buffer)
            ret = 1;

        DetectUrilenFree(NULL, urilend);
    }
    return ret;
}

/**
 * \brief this function is used to initialize the detection engine context and
 *        setup the signature with passed values.
 *
 */

static int DetectUrilenInitTest(DetectEngineCtx **de_ctx, Signature **sig,
                                DetectUrilenData **urilend, const char *str)
{
    char fullstr[1024];
    int result = 0;

    *de_ctx = NULL;
    *sig = NULL;

    if (snprintf(fullstr, 1024, "alert ip any any -> any any (msg:\"Urilen "
                                "test\"; urilen:%s; sid:1;)", str) >= 1024) {
        goto end;
    }

    *de_ctx = DetectEngineCtxInit();
    if (*de_ctx == NULL) {
        goto end;
    }

    (*de_ctx)->flags |= DE_QUIET;

    (*de_ctx)->sig_list = SigInit(*de_ctx, fullstr);
    if ((*de_ctx)->sig_list == NULL) {
        goto end;
    }

    *sig = (*de_ctx)->sig_list;

    *urilend = DetectUrilenParse(str);

    result = 1;

end:
    return result;
}


fir stage

\brief this function is used to initialize the detection engine context and
 *        setup the signature with passed values.
 \brief this function is used to initialize the detection engine context and
 *        setup the signature with passed values.
 \brief this function is used to initialize the detection engine context and
 *        setup the signature with passed values.


 \brief this function is used to initialize the detection engine context and
 *        setup the signature with passed values.
 \brief this function is used to initialize the detection engine context and
 *        setup the signature with passed values.
 \brief this function is used to initialize the detection engine context and
 *        setup the signature with passed values.
 