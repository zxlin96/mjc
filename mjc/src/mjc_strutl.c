#include "mjc.h"
#include "log.h"

char *mjc_strncpy(char *dest, const char *src, U32 dlen)
{
    DBG_PRINTF("====> mjc_strncpy =====> %s\n",src);
   if((src == NULL) || (dest == NULL))
   {
      DBG_PRINTF("null pointer reference src =%s ,dest =%s", src, dest);
	  if(dest != NULL)
	  {
	  	 *dest = '\0';
	  }
	  return dest;
   }

   if( strlen(src)+1 > dlen )
   {
      DBG_PRINTF("truncating:src string length > dest buffer");
      strncpy(dest,src,dlen-1);
      dest[dlen-1] ='\0';
   }
   else
   {
      strcpy(dest,src);
   }
   return dest;
}

S32 mjc_strncmp(const char *s1, const char *s2, S32 n) 
{
   char emptyStr = '\0';
   char *str1 = (char *) s1;
   char *str2 = (char *) s2;

   if (str1 == NULL)
   {
      str1 = &emptyStr;
   }
   if (str2 == NULL)
   {
      str2 = &emptyStr;
   }

   return strncmp(str1, str2, n);
}

S32 mjc_strlen(const char *src)
{
   char emptyStr = '\0';
   char *str = (char *)src;
   
   if(src == NULL)
   {
      str = &emptyStr;
   }	

   return strlen(str);
}