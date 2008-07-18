//
// BXPGEntityImporter.h
// BaseTen
//
// Copyright (C) 2006-2008 Marko Karppinen & Co. LLC.
//
// Before using this software, please review the available licensing options
// by visiting http://basetenframework.org/licensing/ or by contacting
// us at sales@karppinen.fi. Without an additional license, this software
// may be distributed only in compliance with the GNU General Public License.
//
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License, version 2.0,
// as published by the Free Software Foundation.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
//
// $Id$
//

#import <Foundation/Foundation.h>
@class BXDatabaseContext;
@class BXPGEntityConverter;
@class BXPGEntityImporter;


@protocol BXPGEntityImporterDelegate <NSObject>
- (void) entityImporterAdvanced: (BXPGEntityImporter *) importer;
- (void) entityImporter: (BXPGEntityImporter *) importer finishedImporting: (BOOL) succeeded error: (NSError *) error;
@end


@interface BXPGEntityImporter : NSObject 
{
	BXDatabaseContext* mContext;
	BXPGEntityConverter* mEntityConverter;
	NSArray* mEntities;
	NSString* mSchemaName;
	NSArray* mStatements;
	NSArray* mEnabledRelations;
	id <BXPGEntityImporterDelegate> mDelegate;
}
- (void) setDatabaseContext: (BXDatabaseContext *) aContext;
- (void) setEntities: (NSArray *) aCollection;
- (void) setSchemaName: (NSString *) aName;
- (void) setDelegate: (id <BXPGEntityImporterDelegate>) anObject;

- (NSArray *) importStatements;
- (NSArray *) importStatements: (NSArray **) outErrors;
- (void) importEntities;
- (BOOL) enableEntities: (NSError **) outError;
@end