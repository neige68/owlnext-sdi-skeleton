// <version.h>
//
// Project owlnext-sdi-skeleton
// Copyright (C) 2023 neige68
//
// Note: version
//
// Compiler: VC14.2
// Library:  OWL7
//

#ifndef version_h
#define version_h

//------------------------------------------------------------
//
// �����[�X�ԍ�
//
#define VER_RELEASE_STR                 "000"
#define VER_RELEASE                     0

#define VER_BUILD_STR                   "" // "" �������� ".x"
#define VER_BUILD                       0

//
// �����Ж�
//
#define VER_COMPANYNAME                 "neige68"

//
// ���i�o�[�W����
//
#undef VER_PRODUCTVERSION_STR
#undef VER_PRODUCTVERSION
#define VER_PRODUCTVERSION_STR          "0.00"
#define VER_PRODUCTVERSION              0,00,VER_RELEASE,VER_BUILD

//
// ���i��
//
#define VER_PRODUCTNAME                 "Sample"

// �t�@�C���o�[�W����
#define VER_FILEVERSION_STR             "0.00." VER_RELEASE_STR VER_BUILD_STR
#define VER_FILEVERSION                 0,00,VER_RELEASE,VER_BUILD

// �t�@�C������
#define VER_FILEDESCRIPTION             "OWLNext SDI Skeleton"

// ���쌠
#define VER_LEGALCOPYRIGHT_LASTYEAR     "2023"
#define VER_LEGALCOPYRIGHT              "Copyright (C) " VER_LEGALCOPYRIGHT_LASTYEAR " " VER_COMPANYNAME

//------------------------------------------------------------

#endif // version_h

// end of <version.h>
