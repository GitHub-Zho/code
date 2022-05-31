from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
import pandas as pd

chromedriverPath = "C:/Program Files (x86)/Google/Chrome/Application/chromedriver"

option = webdriver.ChromeOptions()
option.add_experimental_option("detach", True)
browser = webdriver.Chrome(executable_path=chromedriverPath)

contents = ""
url = "https://www.wordunscrambler.net/word-list/wordle-word-list"
browser.get(url)
w = WebDriverWait(browser, 10).until(
    EC.presence_of_element_located((By.CLASS_NAME, "list-unstyled")))

words = browser.find_elements_by_class_name("list-unstyled")
for i in words:
    contents = str(contents) + i.text
print(contents)
dfData = contents.split(" ")
df = pd.DataFrame(dfData)
df.to_csv("wordlist.csv", index=False, sep=" ")
