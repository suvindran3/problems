"""
TODO:
"""
import os

def parse_input(file_path: str):
    """
    TODO:
    """
    content = {}
    with open(file_path, 'r', encoding='utf-8') as f:
        raw_input = list(filter(lambda x: len(x) > 0, [s[:-1].strip() for s in f.readlines()]))
    count = int(raw_input[0])
    likes_info = [[] for _ in range(count)]
    dislikes_info = [[] for _ in range(count)]
    for c in range(count * 2):
        split = raw_input[c + 1].split(' ')
        if int(split[0]) > 0:
            for i in range(int(split[0])):
                value = 1 if c % 2 == 0 else -1
                if content.get(split[i + 1]) is None:
                    content[split[i + 1]] = 0
                content[split[i + 1]] += value
                if value == 1:
                    likes_info[c // 2].append(split[i + 1])
                else:
                    dislikes_info[c // 2].append(split[i + 1])
    return count, content, likes_info, dislikes_info

def select_ingredients(threshold: int) -> list[str]:
    """
    TODO:
    """
    i = []
    for k, v in ingredients.items():
        if v >= threshold:
            i.append(k)
    return i


def check_buyers(chosen: list[str]) -> int:
    """
    TODO:
    """
    count = 0
    for ingredient in chosen:
        for i in range(total_customers):
            if ingredient in likes[i] and ingredient not in dislikes[i]:
                count += 1
    return count


base_path = 'input'
for path in os.listdir(base_path):
    total_customers, ingredients, likes, dislikes = parse_input(os.path.join(base_path, path))
    low = 0
    highest_low = 0
    customer_count = 0
    while True:
        chosen_ingredients = select_ingredients(low)
        sol = f'{len(chosen_ingredients)} ' + ' '.join(chosen_ingredients)
        buyers = check_buyers(chosen_ingredients)
        if buyers > customer_count:
            customer_count = buyers
            highest_low = low
        low += 1
        if buyers == 0:
            break

    chosen_ingredients = select_ingredients(highest_low)
    print(f'Threshold: {highest_low}')
    print(ingredients)
    sol = f'{len(chosen_ingredients)} ' + ' '.join(chosen_ingredients)
    print(f'Solution: {sol}')
    buyers = check_buyers(chosen_ingredients)
    print(f'No of customers: {buyers}')
    with open(os.path.join('output', path), 'w', encoding='utf-8') as f:
        f.write(sol)
