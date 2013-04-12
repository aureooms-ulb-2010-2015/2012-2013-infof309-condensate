#include "CondensateParameterLoader.h"

#include <QDomDocument>
#include <QFile>
#include <QTextStream>

CondensateParameterLoader::CondensateParameterLoader(){
	//TODO
}

CondensationParameters CondensateParameterLoader::load(const QString &filename){
	QFile file(filename);

	QDomDocument document;
	if (!file.open(QIODevice::ReadOnly)){
		return CondensationParameters();
	}
	if (!document.setContent(&file)){
		file.close();
		return CondensationParameters();
	}
	file.close();

	QDomElement root = document.documentElement();
	QDomNode node = root.firstChild();
	CondensationParameters parameters;

	parameters.pollingRange = node.toElement().attribute("value").toInt();
	node = node.nextSibling();
	parameters.generatingRange = node.toElement().attribute("value").toInt();
	node = node.nextSibling();
	parameters.spreadRange = node.toElement().attribute("value").toInt();
	node = node.nextSibling();
	parameters.TARGET_MIN_WIDTH = node.toElement().attribute("value").toInt();
	node = node.nextSibling();
	parameters.TARGET_MIN_HEIGHT = node.toElement().attribute("value").toInt();
	node = node.nextSibling();
	parameters.TARGET_MAX_WIDTH = node.toElement().attribute("value").toInt();
	node = node.nextSibling();
	parameters.TARGET_MAX_HEIGHT = node.toElement().attribute("value").toInt();
	node = node.nextSibling();
	parameters.MAX_DIST = node.toElement().attribute("value").toInt();
	node = node.nextSibling();
	parameters.maxCorners = node.toElement().attribute("value").toInt();
	node = node.nextSibling();
	parameters.qualityLevel = node.toElement().attribute("value").toDouble();
	node = node.nextSibling();
	parameters.minDistance = node.toElement().attribute("value").toInt();
	node = node.nextSibling();
	parameters.blockSize = node.toElement().attribute("value").toInt();
	node = node.nextSibling();
	parameters.useHarrisDetector = node.toElement().attribute("value").toInt();
	node = node.nextSibling();
	parameters.k = node.toElement().attribute("value").toDouble();
	node = node.nextSibling();
	parameters.MIN_ACCUMULATOR_ITERATIONS = node.toElement().attribute("value").toInt();
	node = node.nextSibling();
	parameters.R = node.toElement().attribute("value").toInt();
	node = node.nextSibling();
	parameters.matcherIndex = node.toElement().attribute("value").toInt();
	node = node.nextSibling();
	parameters.TRUST_START = node.toElement().attribute("value").toInt();
	node = node.nextSibling();
	parameters.TRUST_DIE = node.toElement().attribute("value").toInt();
	node = node.nextSibling();
	parameters.TRUST_BONUS_FACTOR = node.toElement().attribute("value").toInt();
	node = node.nextSibling();
	parameters.TRUST_MALUS = node.toElement().attribute("value").toInt();
	node = node.nextSibling();
	parameters.MIN_FEATURES = node.toElement().attribute("value").toInt();
	node = node.nextSibling();
	parameters.resamplingPasses = node.toElement().attribute("value").toInt();
	node = node.nextSibling();
	parameters.resamplingRange = node.toElement().attribute("value").toInt();
	node = node.nextSibling();

	return parameters;
}

void CondensateParameterLoader::save(const CondensationParameters &parameters, const QString &filename){
	QDomDocument document;
	QDomElement root = document.createElement("parameters");
	document.appendChild(root);
	QDomElement pollingRange = document.createElement("pollingRange");
	QDomElement generatingRange = document.createElement("generatingRange");
	QDomElement spreadRange = document.createElement("spreadRange");
	QDomElement TARGET_MIN_WIDTH = document.createElement("TARGET_MIN_WIDTH");
	QDomElement TARGET_MIN_HEIGHT = document.createElement("TARGET_MIN_HEIGHT");
	QDomElement TARGET_MAX_WIDTH = document.createElement("TARGET_MAX_WIDTH");
	QDomElement TARGET_MAX_HEIGHT = document.createElement("TARGET_MAX_HEIGHT");
	QDomElement MAX_DIST = document.createElement("MAX_DIST");
	QDomElement maxCorners = document.createElement("maxCorners");
	QDomElement qualityLevel = document.createElement("qualityLevel");
	QDomElement minDistance = document.createElement("minDistance");
	QDomElement blockSize = document.createElement("blockSize");
	QDomElement useHarrisDetector = document.createElement("useHarrisDetector");
	QDomElement k = document.createElement("k");
	QDomElement MIN_ACCUMULATOR_ITERATIONS = document.createElement("MIN_ACCUMULATOR_ITERATIONS");
	QDomElement R = document.createElement("R");
	QDomElement matcherIndex = document.createElement("matcherIndex");
	QDomElement TRUST_START = document.createElement("TRUST_START");
	QDomElement TRUST_DIE = document.createElement("TRUST_DIE");
	QDomElement TRUST_BONUS_FACTOR = document.createElement("TRUST_BONUS_FACTOR");
	QDomElement TRUST_MALUS = document.createElement("TRUST_MALUS");
	QDomElement MIN_FEATURES = document.createElement("MIN_FEATURES");
	QDomElement resamplingPasses = document.createElement("resamplingPasses");
	QDomElement resamplingRange = document.createElement("resamplingRange");
	root.appendChild(pollingRange);
	root.appendChild(generatingRange);
	root.appendChild(spreadRange);
	root.appendChild(TARGET_MIN_WIDTH);
	root.appendChild(TARGET_MIN_HEIGHT);
	root.appendChild(TARGET_MAX_WIDTH);
	root.appendChild(TARGET_MAX_HEIGHT);
	root.appendChild(MAX_DIST);
	root.appendChild(maxCorners);
	root.appendChild(qualityLevel);
	root.appendChild(minDistance);
	root.appendChild(blockSize);
	root.appendChild(useHarrisDetector);
	root.appendChild(k);
	root.appendChild(MIN_ACCUMULATOR_ITERATIONS);
	root.appendChild(R);
	root.appendChild(matcherIndex);
	root.appendChild(TRUST_START);
	root.appendChild(TRUST_DIE);
	root.appendChild(TRUST_BONUS_FACTOR);
	root.appendChild(TRUST_MALUS);
	root.appendChild(MIN_FEATURES);
	root.appendChild(resamplingPasses);
	root.appendChild(resamplingRange);

	pollingRange.setAttribute("value", QString::number(parameters.pollingRange));
	generatingRange.setAttribute("value", QString::number(parameters.generatingRange));
	spreadRange.setAttribute("value", QString::number(parameters.spreadRange));
	TARGET_MIN_WIDTH.setAttribute("value", QString::number(parameters.TARGET_MIN_WIDTH));
	TARGET_MIN_HEIGHT.setAttribute("value", QString::number(parameters.TARGET_MIN_HEIGHT));
	TARGET_MAX_WIDTH.setAttribute("value", QString::number(parameters.TARGET_MAX_WIDTH));
	TARGET_MAX_HEIGHT.setAttribute("value", QString::number(parameters.TARGET_MAX_HEIGHT));
	MAX_DIST.setAttribute("value", QString::number(parameters.MAX_DIST));
	maxCorners.setAttribute("value", QString::number(parameters.maxCorners));
	qualityLevel.setAttribute("value", QString::number(parameters.qualityLevel));
	minDistance.setAttribute("value", QString::number(parameters.minDistance));
	blockSize.setAttribute("value", QString::number(parameters.blockSize));
	useHarrisDetector.setAttribute("value", QString::number(parameters.useHarrisDetector));
	k.setAttribute("value", QString::number(parameters.k));
	MIN_ACCUMULATOR_ITERATIONS.setAttribute("value", QString::number(parameters.MIN_ACCUMULATOR_ITERATIONS));
	R.setAttribute("value", QString::number(parameters.R));
	matcherIndex.setAttribute("value", QString::number(parameters.matcherIndex));
	TRUST_START.setAttribute("value", QString::number(parameters.TRUST_START));
	TRUST_DIE.setAttribute("value", QString::number(parameters.TRUST_DIE));
	TRUST_BONUS_FACTOR.setAttribute("value", QString::number(parameters.TRUST_BONUS_FACTOR));
	TRUST_MALUS.setAttribute("value", QString::number(parameters.TRUST_MALUS));
	MIN_FEATURES.setAttribute("value", QString::number(parameters.MIN_FEATURES));
	resamplingPasses.setAttribute("value", QString::number(parameters.resamplingPasses));
	resamplingRange.setAttribute("value", QString::number(parameters.resamplingRange));

	QDomNode header = document.createProcessingInstruction("xml","version=\"1.0\"");
	document.insertBefore(header,document.firstChild());

	QTextStream out;
	QFile file(filename);
	if (!file.open(QIODevice::WriteOnly)){
		return;
	}
	out.setDevice(&file);
	document.save(out, 4);
	file.close();
}
