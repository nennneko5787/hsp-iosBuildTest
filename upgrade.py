from pbxproj import XcodeProject
from pbxproj.pbxsections.PBXFileReference import PBXFileReference

project = XcodeProject.load("hspproj.xcodeproj/project.pbxproj")

project.add_file("iHSP30/obaq/physics/vessel.h")
project.remove_file_by_id("1E4AFEAD25E00F4700213810")
print(project.get_files_by_name("vessel.h"))
for file in project.get_files_by_name("vessel.h"):
    file: PBXFileReference = file
    print(file.get_id())

project.save()
