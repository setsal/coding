import json
import os

with open('Blind Curated 75.json') as f:
  data = json.load(f)

# print(data['questions'])

for quest in data['questions']:
    filename = 'Blind Curated 75/' + str(quest['id']) + '. '  + quest['title'] + '.cpp'
    f = open(filename,"w+")
    f.close()

print('done')