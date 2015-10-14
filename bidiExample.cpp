#include "unicode/utypes.h"
#include "unicode/uchar.h"
#include "unicode/localpointer.h"
#include "unicode/ubidi.h"
#include <unicode/unistr.h>
#include<string>
#include<iostream>
using namespace std;
using namespace icu;
using icu::UnicodeString;
int main(int argc,char* argv[])
{



    UnicodeString us(argv[1]);


    UBiDi * bidi=ubidi_open ();

    UErrorCode errorCode = U_ZERO_ERROR;

    UBiDiLevel paraLevel= UBIDI_DEFAULT_LTR;

    ubidi_setPara(bidi,us.getBuffer(),us.length(),paraLevel,nullptr,&errorCode);



    if (U_SUCCESS(errorCode))
    {
        UnicodeString Ustring(ubidi_getText(bidi));
        string Ustr;
        Ustring.toUTF8String(Ustr);
        int32_t count=ubidi_countRuns(bidi,&errorCode);
        int32_t logicalStart, length;
        for(int32_t i=0; i<count; i++) {

            UBiDiDirection dir=ubidi_getVisualRun(bidi, i, &logicalStart, &length);
            string dirstr = "UBIDI_LTR";
            if (dir == UBIDI_RTL)
                dirstr = "UBIDI_RTL";

            string str55;
        UnicodeString temp=Ustring.tempSubString(logicalStart,length);




            temp.toUTF8String(str55);

            cout << "VisualRun \t" << dirstr << "\t"<< logicalStart<<'\t'<<length<<'\t'<<str55<<endl;

        }

    }
    else
    {
        cout << "Failed" << endl;
    }







    return 0;
}


