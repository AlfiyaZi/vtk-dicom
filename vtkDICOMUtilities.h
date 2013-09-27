/*=========================================================================

  Program: DICOM for VTK

  Copyright (c) 2012-2013 David Gobbi
  All rights reserved.
  See Copyright.txt or http://www.cognitive-antics.net/bsd3.txt for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#ifndef __vtkDICOMUtilities_h
#define __vtkDICOMUtilities_h

#include <vtkSystemIncludes.h>
#include "vtkDICOMModule.h"

class vtkStringArray;

//! Utility functions for use with DICOM classes.
class VTK_DICOM_EXPORT vtkDICOMUtilities
{
public:

  //! Generate a random UID.
  static std::string GenerateUID();

  //! Generate a series of UIDs, sorted from low to high.
  /*!
   *  The generated UIDs will be appended to the provided string array.
   *  Generating a batch of UIDs is more efficient than calling
   *  GenerateUID() repeatedly.  As an added bonus, the returned UIDs
   *  are sorted.
   */
  static void GenerateUIDs(vtkStringArray *uids, vtkIdType n);

  //! Numerically compare two UIDs, returns -1, 0, or +1.
  static int CompareUIDs(const char *u1, const char *u2);

  //! Generate a DICOM date time string in the given timezone.
  /*!
   *  The time zone is to be given in the DICOM format of
   *  +HHMM or -HHMM where HH is the hour offset and MM is the
   *  minute offset.  The sign is mandatory and cannot be omitted.
   */
  static std::string GenerateDateTime(const std::string& zone);

  //! Get the UID for this DICOM implementation.
  static const char *GetImplementationClassUID();

  //! Set the UID for this DICOM implementation.
  /*!
   *  The supplied UID will be copied into a static storage area,
   *  and used for all future calls to GetImplementationClassUID.
   *  The ImplementationClassUID appears in the DICOM meta header.
   */
  static void SetImplementationClassUID(const char *uid);

  //! Get the versioned name for this DICOM implementation.
  static const char *GetImplementationVersionName();

  //! Set the versioned name for this DICOM implementation.
  /*!
   *  The supplied name will be copied into a static storage area,
   *  and used for all future calls to GetImplementationVersionName.
   *  The ImplementationVersionName appears in the DICOM meta header.
   */
  static void SetImplementationVersionName(const char *name);

protected:
  vtkDICOMUtilities();
  ~vtkDICOMUtilities();

  static char ImplementationClassUID[65];
  static char ImplementationVersionName[17];

private:
  vtkDICOMUtilities(const vtkDICOMUtilities&);  // Not implemented.
  void operator=(const vtkDICOMUtilities&);  // Not implemented.
};

#endif /* __vtkDICOMUtilities_h */
