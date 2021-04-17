"""
This is a question done for Love Babbar's question sheet on graph.
The link to this question: https://www.geeksforgeeks.org/given-sorted-dictionary-find-precedence-characters/
Can also be done on GeeksForGeeksPractice.
"""

from queue import Queue
import pdb;

class Solution:
    def get_graph_from_words(self, words: list) -> dict:
        graph = {}
        
        # Building graph
        for word in words:
            for character in word:
                graph[character] = []
                
        # Creating adjacency list:
        for word in words:
            for i in range(len(word) - 1):
                current_char = word[i]
                next_char = word[i + 1]
                
                # check if the word does not exists in adj list of current char then insert
                # it into the word
                if next_char not in graph[current_char]:
                    graph[current_char].append(next_char)
        
        return graph
    
    def get_indegree_map(self, graph: dict) -> dict:
        indegree = dict.fromkeys(graph.keys(), 0)
        
        for node in graph:
            for neighbour in graph[node]:
                # pdb.set_trace();
                if node != neighbour:
                        indegree[neighbour] += 1
                
        return indegree
    
    def build_queue(self, indegree: dict) -> Queue:
        q = Queue()
        
        for node, idegree in indegree.items():
            if idegree == 0:
                q.put(node)
        
        return q
    
    def get_sequence_from_topological_sort(self, graph: dict, indegree: dict) -> list:
        sequence = []
        q = self.build_queue(indegree)
        
        while q.qsize() > 0:
            node: int = q.get()
            
            for neighbour in graph[node]:
                indegree[neighbour] -= 1
                if indegree[neighbour] == 0:
                    q.put(neighbour)
        
        return sequence
        
    def answer(self, words: list) -> list:
        graph = self.get_graph_from_words(words); print(graph)
        indegree = self.get_indegree_map(graph); print(2, graph, indegree)
        sequence = self.get_sequence_from_topological_sort(graph, indegree); print(3, graph, indegree, sequence)
        return sequence
    
    
words = ["baa", "abcd", "abca", "cab", "cad"]
print("Order: ", Solution().answer(words))