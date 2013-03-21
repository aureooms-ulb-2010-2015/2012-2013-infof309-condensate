#############################################################################
# Makefile for building: condensate
# Generated by qmake (2.01a) (Qt 4.8.1) on: Thu Mar 21 18:05:22 2013
# Project:  condensate.pro
# Template: app
# Command: /usr/bin/qmake -o Makefile condensate.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_WEBKIT -DQT_NO_DEBUG -DQT_OPENGL_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -m64 -pipe -std=c++0x -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++-64 -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtOpenGL -I/usr/include/qt4 -I/usr/local/lib -I../lib309 -I/usr/local/include/opencv -I/usr/local/include -I/usr/X11R6/include -I.
LINK          = g++
LFLAGS        = -m64 -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib/x86_64-linux-gnu -L/usr/X11R6/lib64 -lv4l2 -lX11 -L ../ -llib309 /usr/local/lib/libopencv_calib3d.so /usr/local/lib/libopencv_contrib.so /usr/local/lib/libopencv_core.so /usr/local/lib/libopencv_features2d.so /usr/local/lib/libopencv_flann.so /usr/local/lib/libopencv_gpu.so /usr/local/lib/libopencv_highgui.so /usr/local/lib/libopencv_imgproc.so /usr/local/lib/libopencv_legacy.so /usr/local/lib/libopencv_ml.so /usr/local/lib/libopencv_nonfree.so /usr/local/lib/libopencv_objdetect.so /usr/local/lib/libopencv_photo.so /usr/local/lib/libopencv_stitching.so /usr/local/lib/libopencv_ts.so /usr/local/lib/libopencv_video.so /usr/local/lib/libopencv_videostab.so -lQtOpenGL -lQtGui -lQtCore -lGL -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = Main.cpp \
		MainWindow.cpp moc_MainWindow.cpp \
		qrc_img.cpp
OBJECTS       = Main.o \
		MainWindow.o \
		moc_MainWindow.o \
		qrc_img.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/link_pkgconfig.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/opengl.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		condensate.pro
QMAKE_TARGET  = condensate
DESTDIR       = 
TARGET        = condensate

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: condensate.pro  /usr/share/qt4/mkspecs/linux-g++-64/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/link_pkgconfig.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/opengl.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/x86_64-linux-gnu/libQtOpenGL.prl \
		/usr/lib/x86_64-linux-gnu/libQtGui.prl \
		/usr/lib/x86_64-linux-gnu/libQtCore.prl
	$(QMAKE) -o Makefile condensate.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/link_pkgconfig.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/opengl.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/x86_64-linux-gnu/libQtOpenGL.prl:
/usr/lib/x86_64-linux-gnu/libQtGui.prl:
/usr/lib/x86_64-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile condensate.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/condensate1.0.0 || $(MKDIR) .tmp/condensate1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/condensate1.0.0/ && $(COPY_FILE) --parents MainWindow.h .tmp/condensate1.0.0/ && $(COPY_FILE) --parents img.qrc .tmp/condensate1.0.0/ && $(COPY_FILE) --parents Main.cpp MainWindow.cpp .tmp/condensate1.0.0/ && (cd `dirname .tmp/condensate1.0.0` && $(TAR) condensate1.0.0.tar condensate1.0.0 && $(COMPRESS) condensate1.0.0.tar) && $(MOVE) `dirname .tmp/condensate1.0.0`/condensate1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/condensate1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_MainWindow.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_MainWindow.cpp
moc_MainWindow.cpp: ../lib309/BasicWindow.h \
		../lib309/VideoStreamReader.h \
		../lib309/Stream.h \
		../lib309/VideoStreamInfo.h \
		../lib309/VideoPlayControlsWidget.h \
		../lib309/PlayPauseButtonWidget.h \
		../lib309/SwaperWidget.h \
		../lib309/TimeControlWidget.h \
		../lib309/TimeDisplayerWidget.h \
		../lib309/StreamDisplayer.h \
		../lib309/Mat2QImage.h \
		../lib309/InputChoiceWidget.h \
		../lib309/NetworkStreamInputDialog.h \
		../lib309/CustomButton.h \
		../lib309/CustomTextInput.h \
		../lib309/CustomComboBox.h \
		../lib309/ProcessingChoiceWidget.h \
		../lib309/ImageDisplayerWidget.h \
		../lib309/FrameProcessor.h \
		../lib309/VideoStreamProcessor.h \
		../lib309/ImageDisplayerWidgetImpl.h \
		MainWindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) MainWindow.h -o moc_MainWindow.cpp

compiler_rcc_make_all: qrc_img.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_img.cpp
qrc_img.cpp: img.qrc \
		img/play_icon.png \
		img/pause_icon.png \
		qss/QComboBoxDropDown.qss \
		qss/timeControlSlider.qss \
		qss/CustomButton.qss \
		qss/QComboBox.qss
	/usr/bin/rcc -name img img.qrc -o qrc_img.cpp

compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean 

####### Compile

Main.o: Main.cpp MainWindow.h \
		../lib309/BasicWindow.h \
		../lib309/VideoStreamReader.h \
		../lib309/Stream.h \
		../lib309/VideoStreamInfo.h \
		../lib309/VideoPlayControlsWidget.h \
		../lib309/PlayPauseButtonWidget.h \
		../lib309/SwaperWidget.h \
		../lib309/TimeControlWidget.h \
		../lib309/TimeDisplayerWidget.h \
		../lib309/StreamDisplayer.h \
		../lib309/Mat2QImage.h \
		../lib309/InputChoiceWidget.h \
		../lib309/NetworkStreamInputDialog.h \
		../lib309/CustomButton.h \
		../lib309/CustomTextInput.h \
		../lib309/CustomComboBox.h \
		../lib309/ProcessingChoiceWidget.h \
		../lib309/ImageDisplayerWidget.h \
		../lib309/FrameProcessor.h \
		../lib309/VideoStreamProcessor.h \
		../lib309/ImageDisplayerWidgetImpl.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Main.o Main.cpp

MainWindow.o: MainWindow.cpp MainWindow.h \
		../lib309/BasicWindow.h \
		../lib309/VideoStreamReader.h \
		../lib309/Stream.h \
		../lib309/VideoStreamInfo.h \
		../lib309/VideoPlayControlsWidget.h \
		../lib309/PlayPauseButtonWidget.h \
		../lib309/SwaperWidget.h \
		../lib309/TimeControlWidget.h \
		../lib309/TimeDisplayerWidget.h \
		../lib309/StreamDisplayer.h \
		../lib309/Mat2QImage.h \
		../lib309/InputChoiceWidget.h \
		../lib309/NetworkStreamInputDialog.h \
		../lib309/CustomButton.h \
		../lib309/CustomTextInput.h \
		../lib309/CustomComboBox.h \
		../lib309/ProcessingChoiceWidget.h \
		../lib309/ImageDisplayerWidget.h \
		../lib309/FrameProcessor.h \
		../lib309/VideoStreamProcessor.h \
		../lib309/ImageDisplayerWidgetImpl.h \
		../lib309/Algorithm_NoProcessing.h \
		../lib309/Algorithm_Tagging.h \
		../lib309/Algorithm_Sub_Tagging.h \
		../lib309/Algorithm_AccumulateBackground.h \
		../lib309/Algorithm_FeaturesTracker.h \
		../lib309/Algorithm_TagAnTrack.h \
		../lib309/Algorithm_Sub_BinaryMask.h \
		../lib309/Algorithm_BinaryMaskWithOriginalFrame.h \
		../lib309/Algorithm_Watershed.h \
		../lib309/Algorithm_OomsChallenge.h \
		../lib309/Target.h \
		../lib309/Algorithm_CustomCondensationV1.h \
		../lib309/Algorithm_CustomCondensationTemplateV1.h \
		../lib309/Algorithm_CustomCondensation.h \
		../lib309/Matcher_TargetMatcherV2_BinaryMask.h \
		../lib309/Target_CondensationTargetV1.h \
		../lib309/Target_CondensationTarget.h \
		../lib309/Matcher_TargetMatcher.h \
		../lib309/Algorithm_CustomCondensationTemplateV2.h \
		../lib309/Matcher_GreyLevelDistanceMatcher.h \
		../lib309/Target_CondensationTargetV2.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o MainWindow.o MainWindow.cpp

moc_MainWindow.o: moc_MainWindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_MainWindow.o moc_MainWindow.cpp

qrc_img.o: qrc_img.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_img.o qrc_img.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

