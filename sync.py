import os
import shutil
import glob
from tqdm import tqdm

def get_problem_ids_from_submissions(submissions_dir):
    return [
        name for name in os.listdir(submissions_dir)
        if os.path.isdir(os.path.join(submissions_dir, name))
    ]

def organize_problem_files():
    base_dir = os.path.expanduser("~/re-algo")
    sub_dir=os.path.expanduser("~/SyncBOJ")
    submissions_dir = os.path.join(sub_dir, "submissions")
    problem_ids = get_problem_ids_from_submissions(submissions_dir)

    for problem_id in tqdm(problem_ids, desc="문제 파일 정리 중"):
        try:
            cpp_candidates = glob.glob(os.path.join(base_dir, "**", f"{problem_id}*.cpp"), recursive=True)
            if not cpp_candidates:
                raise FileNotFoundError(f"[!] {problem_id} 관련 .cpp 파일을 찾을 수 없습니다.")

            cpp_path = cpp_candidates[0]  # 여러 개일 경우 첫 번째만 사용
            parent_dir = os.path.dirname(cpp_path)

            if os.path.basename(parent_dir) == "solutions":
                # case 1: cpp가 solution 내부에 있음 → 상위 폴더가 문제 폴더
                v_dir = os.path.join(os.path.dirname(parent_dir), f"v{problem_id}")
            else:
                # case 2: cpp가 solution 외부에 있음 → solution 폴더가 같은 위치에 있어야 함
                possible_solution_dir = os.path.join(parent_dir, "solutions")
                if not os.path.isdir(possible_solution_dir):
                    raise Exception(f"[!] {problem_id} 관련 solutions 디렉토리가 존재하지 않음 (위치: {parent_dir})")
                v_dir = os.path.join(parent_dir, f"v{problem_id}")

            if os.path.exists(v_dir):
                continue
            os.makedirs(v_dir, exist_ok=True)

            # cpp 파일 이동
            shutil.move(cpp_path, os.path.join(v_dir, os.path.basename(cpp_path)))

            # main.cc 이동
            main_cc_path = os.path.join(submissions_dir, str(problem_id), "main.cc")
            if os.path.exists(main_cc_path):
                shutil.move(main_cc_path, os.path.join(v_dir, "main.cc"))

        except Exception as e:
            print(f"[!] 문제 {problem_id} 스킵됨: {e}")

# 실행
organize_problem_files()
