from jinja2 import Template
import glob
import os

for fname in glob.iglob('./*.template.js'):
    with open(fname) as f:
        templated = Template(f.read()).render(env=os.environ)
    with open(fname.replace('.template.js', '.gen.js'), 'w') as f:
        f.write(templated)