import os

from pbxproj import XcodeProject
from pbxproj.pbxsections.PBXFileReference import PBXFileReference

project = XcodeProject.load("hspproj.xcodeproj/project.pbxproj")
bs = "\\"

folder = "iHSP30"
for root, _, files in os.walk(folder):
    for _file in files:
        rel_path = os.path.relpath(os.path.join(root, _file), folder)
        for file in project.get_files_by_name(_file):
            file: PBXFileReference = file
            project.remove_file_by_id(file.get_id())
        for file in project.get_files_by_path(f"iHSP30/{rel_path.replace(bs, '/')}"):
            file: PBXFileReference = file
            project.remove_file_by_id(file.get_id())
        if "iosgp" in _file:
            continue
        project.add_file(f"iHSP30/{rel_path.replace(bs, '/')}")
        print(rel_path)


project.save()
