/**
 * <pre>
 *
 *     author : wgc
 *     time   : 2021/12/16
 *     desc   :
 *     version: 1.0
 * 
 * </pre>
 */


#include <LogUtils.h>
#include <jni.h>
#include <CommonUtils.h>
#include <string.h>
#include <empty.h>

/**
 * jbyteArray转char
 */
char *convertJByteArrayToChars(JNIEnv *env, jbyteArray byteArray) {
    char *chars = null;
    jbyte *bytes;
    bytes = env->GetByteArrayElements(byteArray, null);
    int len = env->GetArrayLength(byteArray);
    chars = new char[len + 1];
    memset(chars, 0, static_cast<size_t>(len + 1));
    memcpy(chars, bytes, static_cast<size_t>(len));
    env->ReleaseByteArrayElements(byteArray, bytes, 0);
    return chars;
}

/**
 * 将hexarr 转成16进制的字符串
 */
std::string arr2hex(const unsigned char *arr, size_t len) {
    size_t i;
    std::string res;
    char tmp[3];
    const char *tab = "0123456789ABCDEF";

    res.reserve(len * 2 + 1);
    for (i = 0; i < len; ++i) {
        tmp[0] = tab[arr[i] >> 4];
        tmp[1] = tab[arr[i] & 0xf];
        tmp[2] = '\0';
        res.append(tmp);
    }

    return res;
}
