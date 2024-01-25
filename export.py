import os
import shutil
import zipfile

export_filename = "export-testcases"

path = os.getcwd()
problems = [
    f for f in os.listdir(path) 
        if (os.path.isdir(f) and os.path.isfile(os.path.join(f, "PROBLEM")))
]

if os.path.exists(os.path.join(path, export_filename)):
    shutil.rmtree(os.path.join(path, export_filename))

def export(problem):
    print("exporting " + problem)

    new_path = os.path.join(path, export_filename, problem)
    os.makedirs(new_path, exist_ok=True)
    
    os.makedirs(os.path.join(new_path, "input"), exist_ok=True)
    os.makedirs(os.path.join(new_path, "output"), exist_ok=True)

    if not os.path.isdir(os.path.join(problem, "tests")):
        print("no tests folder: " + problem)
        return

    testcases = os.path.join(problem, "tests")
    for test in os.listdir(testcases):
        if test.endswith(".in"):
            test_name = test[:-3]
            test = os.path.join(testcases, test)
            shutil.copy(test, os.path.join(new_path, "input", test_name + ".txt"))
        if test.endswith(".diff"):
            test_name = test[:-5]
            test = os.path.join(testcases, test)
            shutil.copy(test, os.path.join(new_path, "output", test_name + ".txt"))

    shutil.make_archive(new_path, "zip", new_path)


for problem in problems:
    export(problem)


