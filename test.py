# coding: utf-8
from PIL import Image, ImageFont

from handright import Template, handwrite

text = "航空航天可以分为航空、航天两大不同的领域。航空主要是指在大气层内的飞行，而航天主要是指在大气层外的飞行。航空航天与其他学科相互促进发展，能为社会带来巨大的间接经济效益。\n飞行器主要可以根据工作海拔的不同分为航空器和航天器，还有火箭、导弹。航空器可根据密度不同分为轻于空气的航空器（如气球、飞艇）和重于空气的航空器。早在18世纪，就有人成功利用浮力制造出热气球完成人类飞天的梦想。重于空气的航空器又包括固定翼、旋翼航空器，扑翼机和倾转旋翼机。而航天器根据是否载人可以分为无人航天器和载人航天器，无人航天器包括人造地球卫星和空间探测器，载人航天器有载人飞船和航天飞机。我国在导弹、运载火箭、人造地球卫星和载人航天方面也取得了一定的成就。航空航天的先进技术主要有隐身技术、临近空间技术、高超声速技术。"
template = Template(
    background=Image.new(mode="1", size=(2970, 2100), color=1),
    font_size=100,
    font=ImageFont.truetype("./hhh/hhh1.ttf"),
)
images = handwrite(text, template)
for im in images:
    assert isinstance(im, Image.Image)
    im.show()
