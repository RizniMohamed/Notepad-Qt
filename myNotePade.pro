QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

VERSION=2.0
TARGET=RC_Notepad
DEFINES += APP_VERSION=$$VERSION

SOURCES += \
    colorpickerrc.cpp \
    count.cpp \
    helpwin.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    colorpickerrc.h \
    count.h \
    helpwin.h \
    mainwindow.h

FORMS += \
    colorpickerrc.ui \
    helpwin.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

RESOURCES = res.qrc

ANDROID_ABIS = armeabi-v7a arm64-v8a x86 x86_64


android: include(C:/Users/user/AppData/Local/Android/Sdk/android_openssl-master/openssl.pri)

DISTFILES += \
    android/AndroidManifest.xml \
    android/AndroidManifest.xml \
    android/AndroidManifest.xml \
    android/AndroidManifest.xml \
    android/AndroidManifest.xml \
    android/AndroidManifest.xml \
    android/AndroidManifest.xml \
    android/AndroidManifest.xml \
    android/build.gradle \
    android/build.gradle \
    android/build.gradle \
    android/build.gradle \
    android/build.gradle \
    android/build.gradle \
    android/build.gradle \
    android/build.gradle \
    android/gradle.properties \
    android/gradle.properties \
    android/gradle.properties \
    android/gradle.properties \
    android/gradle.properties \
    android/gradle.properties \
    android/gradle.properties \
    android/gradle.properties \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew \
    android/gradlew \
    android/gradlew \
    android/gradlew \
    android/gradlew \
    android/gradlew \
    android/gradlew \
    android/gradlew \
    android/gradlew.bat \
    android/gradlew.bat \
    android/gradlew.bat \
    android/gradlew.bat \
    android/gradlew.bat \
    android/gradlew.bat \
    android/gradlew.bat \
    android/gradlew.bat \
    android/res/values/libs.xml \
    android/res/values/libs.xml \
    android/res/values/libs.xml \
    android/res/values/libs.xml \
    android/res/values/libs.xml \
    android/res/values/libs.xml \
    android/res/values/libs.xml \
    android/res/values/libs.xml

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android
