./client 58999 "$(python3 -c 'import lorem, random; emojis = ["😊", "🚀", "🔥", "🎉", "💡", "💻", "📚", "🧠", "🌟", "✨"]; text = lorem.paragraph() * 300; words = text.split(); print(" ".join([word + (random.choice(emojis) if random.random() < 0.3 else "") for word in words]))')"
