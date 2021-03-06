A simple library to read WLAN access point information (locutor).

This library relies on the code of Google Gears.

Download the gears source and the third_party sources from Google SVN.

Requirements:
 - Cygwin with make, M4, python, zip
 - candle (http://wix.codeplex.com/)
 - VS9 (bin in path)
   - copy mspdb80.dll from C:\Program Files\Microsoft Visual Studio 9.0\Common7\IDE to VC\bin
   - it might be necessary to copy also mspdbsrv.exe and mspdbcore.dll in case of C1902-errors.
   - copy link.exe to link.ms.exe in VS9/bin
   - if needed, copy msobj80.dll to from Common7/IDE VC/lib, better to VC\bin or put Common7 in %PATH% (Linker Tools Error LNK2023)
 - env variable INCLUDE
   C:\Program Files\Microsoft Visual Studio 9.0\VC\include;C:\Program Files\Microsoft SDKs\Windows\v7.0\Include;C:\Program Files\Microsoft Visual Studio 9.0\VC\atlmfc\include;C:\Program Files\Java\jdk1.6.0_21\include;C:\Program Files\Java\jdk1.6.0_21\include\win32
 - env variable LIB
   C:\Program Files\Microsoft Visual Studio 9.0\VC\lib;C:\Program Files\Microsoft SDKs\Windows\v7.0\Lib;C:\Program Files\Microsoft Visual Studio 9.0\VC\atlmfc\lib;C:\Program Files\Java\jdk1.6.0_21\lib
 - in case of temporary files of the visual c compiler enable the temp-exports in the bashrc file (cygwin-install dir, home)

For building
  - choose the correct feature configuration (name it tools/PLConfig.mk)
  - for windows run make PRODUCT=JNI
  - for linux run make PRODUCT=JNI
  - for android run makeAndroid.sh
   
Required changes to sources for Windows 7 (VS9) build
- third_party/zlib/zutil.h (line 200-202) (*)
  surround by #if _MSC_VER < 1500 / #endif

  #if _MSC_VER < 1500 
  #    if !defined(vsnprintf) && !defined(NO_vsnprintf)
  #      define vsnprintf _vsnprintf
  #    endif
  #endif
  (needed because also VC9 defines now vsnprintf)
- third_party/passthru_app/urlmon_ie7.h (line 276-278)
  #if _MSC_VER < 1500
  enum ExtraQUERYOPTION {
    QUERY_USES_HISTORYFOLDER = QUERY_IS_SAFE + 1
  };
  #endif
- tools/config.mk 
  - link -> link.ms
  - @echo. -> @echo
- replace line 937 in rules.mk by MSI_BUILD=`expr $(BUILD) \* 100 \+ $(PATCH)`
  
Required changes to sources for Windows 7 (VS9) build of locutor  
  
- gears/base/common/message_queue_win32.cc (*)
  at the end of includes (now) the following lines are needed

  #include <atlbase.h>        // Base ATL classes
  extern CComModule _Module;  // Global _Module
  #include <atlwin.h>         // ATL windowing classes
  
- gears/base/common/basictypes.h
  after include <stddef.h>
  
  #ifdef _JNI
   #include <jni.h>
  #endif
  
  surround typedef int int32;
  
  #ifndef _JNI
   typedef int                 int32;
  #endif
  ...
  #ifndef _JNI
   typedef unsigned int       uint32;
  #endif

Before building locutor, first build Gears (e.g. make BROWSER=FF36)! 
Locutor needs product_constants.h generated by Gears make. Before 
building locutor plugins please rune make installers on gears.

Required changes on Ubuntu
- third_party\googleurl\src\url_parse.cc
  #if OS == Linux
  #include "stdlib.h"
  #endif
- third_party\jsoncpp\json_reader.cc, json_writer.cc, json_value.cc
  #if OS == Linux
  #include "stdlib.h"
  #include <string.h>
  #endif
- third_party\skia\src\core\DkDebug_stdio.cpp, end of SkDebugf
  #if OS == Linux
    fprintf(stderr, "%s", buffer);
  #else
    fprintf(stderr, buffer);
  #endif
- base\common\basictypes.h
async_router.cc, base_class.cc, base64.cc, byte_store.cc, byte_store_test.cc, 
  database_name_table.cc, event.cc, event_test.cc, file.cc, file_test.cc, http_utils.cc, js_marshal.cc
  js_runner_utils.cc, js_types.cc, leak_counter.cc, memory_buffer_test.cc, message_queue.cc, message_service.cc, 
  message_service_test.cc, mime_detect.cc, mutex.cc, mutex_posix.cc, mutex_test.cc, name_value_table.cc, 
  name_value_table_test.cc, paths.cc, permissions_db.cc, permissions_db_test.cc, permissions_manager.cc, 
  position_table.cc, png_utils.cc, scoped_refptr_test.cc, security_model.cc, security_model_test.cc, serialization.cc, 
  serialization_test.cc, shortcut_table.cc, sqlite_wrapper.cc, sqlite_wrapper_test.cc, stopwatch.cc, stopwatch_posix.cc,
  string16.cc, string_utils_test.cc, thread.cc, thread_locals.cc, thread_posix.cc
  #if OS == Linux
  #include "stdlib.h"
  #include <string.h>
  #endif
- string_utils.cc
  #if OS == Linux
  #include <limits.h>
  #endif
- desktop/desktop.cc, cctest/test.cc
  make operator precedence explicit