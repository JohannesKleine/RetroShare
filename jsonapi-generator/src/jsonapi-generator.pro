# SPDX-FileCopyrightText: (C) 2004-2019 Retroshare Team <contact@retroshare.cc>
# SPDX-License-Identifier: CC0-1.0

TARGET = jsonapi-generator

CONFIG += qt
#QMAKE_LFLAGS+=-v
QMAKE_CXXFLAGS+=-stdlib=libc++

QT *= core xml
QT -= gui

SOURCES += jsonapi-generator.cpp
