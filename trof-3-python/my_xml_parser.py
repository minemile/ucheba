from lxml import etree

XML_PATH = 'music_catalogue.xml'

class MyXmlMusicParser(object):

    def __init__(self, xml_path):
        self.tree = etree.parse(XML_PATH) # Task #2

    def __str__(self):
        """Pretty print. Task #3"""
        return etree.tostring(self.tree, pretty_print=True)

    def add_elements(self, artists, albums, songs):
        """Adds elemens. Artist->album->songs. Task #4"""
        for artist in artists:
            artist = etree.SubElement(self.tree.getroot(), "Artist", **artist)
            for album in albums:
                album = etree.SubElement(artist, "Album", **album)
                for song in songs:
                    etree.SubElement(album, "Song", **song)

    def delete_elements_by_xpath(self, xpath):
        """Deletes elements(and childs) by xpath. Task #5"""
        for element in self.tree.xpath(xpath):
            element.getparent().remove(element)

    def print_attr(self, attr_name, to_print=False):
        """Prints attr from all elements. Task #6"""
        elements = self.tree.findall(".//*[@{0}]".format(attr_name))
        if not to_print:
            return elements
        for element in elements:
            print(element.get(attr_name))

    def get_elements_by_root(self, root, to_print=False):
        """Prints elements, that root's child. Task #2.2"""
        childrens = root.getchildren()
        if not to_print:
            return childrens
        for children in childrens:
            print(etree.tostring(children, pretty_print=True))


    def get_elements_by_attr_value(self, attr_value, to_print=False):
        """Task #2.3"""


if __name__ == '__main__':
    parser = MyXmlMusicParser(XML_PATH)
    artists = [{'Name': "Kanye West"}]
    albums = [{'Title': "Life Of Pablo", 'Release_data': "2K16", 'Type': "Album"}]
    songs = [{'No': "1", "Title":"Ultralight Beam", "Music": "Kanye West", "Length": "5:20", "Genre":"Hip-hop"},
             {'No': "2", "Title":"Fade", "Music": "Larry Heard, Robert Owens", "Length": "3:14", "Genre":"House"}]
    parser.add_elements(artists, albums, songs)
    # Delete Artist "Metallica"
    parser.delete_elements_by_xpath("//Artist[@Name='Metallica']")
    parser.print_attr("Name")
    parser.get_elements_by_root(parser.tree.getroot())
    parser.get_elements_by_attr_value("Paris")
    #print(parser)
